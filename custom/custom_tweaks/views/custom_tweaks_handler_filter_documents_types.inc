<?php


class custom_tweaks_handler_filter_documents_types extends views_handler_filter_in_operator {

  function construct() {
    parent::construct();
    $this->additional_fields['field_type'] = array(
      'table' => 'field_data_field_type',
      'field' => 'field_type_value',
    );
    $this->additional_fields['field_alias'] = array(
      'table' => 'field_data_field_alias',
      'field' => 'field_alias_value',
    );
  }

  /**
   * {@inheritdoc}
   */
  public function get_value_options() {
    if (!isset($this->value_options)) {
      $this->value_title = t('Helios types');
      $options = array(
       1 => t('Document introductions'),
       2 => t('Document sections'),
       3 => t('Patterns'),
       4 => t('Metaphors'),
       5 => t('Encyclopedia introd.'),
       6 => t('Info. reports: introd.'),
       7 => t('Info. reports: sections'),
       'all' => 'All',
      );
      $this->value_options = $options;
    }
  }

  public function value_form(&$form, &$form_state) {
    parent::value_form($form, $form_state);

    $form['value']['#no_convert'] = TRUE;
  }

  /**
   * Runs the query for this filter.
   *
   * @see $this->query->add_where() for other types of conditions that you may want to write.
   */
  public function query() {
    // $this->value is not empty when the above form has been filled out.
    if (empty($this->value)) {
      return;
    }
    $this->ensure_my_table();
    $this->add_additional_fields();

    $value = $this->value;

    $field_type_table = $this->additional_fields['field_type']['table'];
    $field_type_column = $this->additional_fields['field_type']['field'];

    $field_alias_table = $this->additional_fields['field_alias']['table'];
    $field_alias_column = $this->additional_fields['field_alias']['field'];

    $field_type = "$field_type_table.$field_type_column";
    $field_alias = "$field_alias_table.$field_alias_column";

    $allTypes = array('dmain', 'dpart', 'encyc', 'cmain', 'cpart');

    if ($value['all'] === 'all') {
      $this->query->add_where_expression($this->options['group'], "$field_type IN ('" . implode("', '", $allTypes) . "')");
      return;
    }

    $whereExpressionArray = array();

    foreach ($value as $id => $result) {
      if ($result !== 0) {

        switch ($result) {
          case 1:
            $whereExpressionArray[] = "
            $field_type = 'dmain'
            AND $field_alias NOT LIKE '%_x_chi_h_1'
            AND $field_alias NOT LIKE '%_8_pat_h_1'
            ";
            break;
          case 2:
            $whereExpressionArray[] = "$field_type = 'dpart'";
            break;
          case 3:
            $whereExpressionArray[] = "
            $field_type = 'dmain'
            AND $field_alias LIKE '%_8_pat_h_1'
            ";
            break;
          case 4:
            $whereExpressionArray[] = "
            $field_type = 'dmain'
            AND $field_alias LIKE '%_x_chi_h_1'
            ";
            break;
          case 5:
            $whereExpressionArray[] = "$field_type = 'encyc'";
            break;
          case 6:
            $whereExpressionArray[] = "$field_type = 'cmain'";
            break;
          case 7:
            $whereExpressionArray[] = "$field_type = 'cpart'";
            break;
        }
      }
    }

    // Adding brackets.
    array_walk($whereExpressionArray , function(&$item, $key) {
      $item = "($item)";
    });

    $this->query->add_where_expression($this->options['group'], implode(' OR ', $whereExpressionArray));
  }


  /**
   * Add 'additional' fields to the query.
   *
   * @param array $fields
   *   An array of fields. The key is an identifier used to later find the field
   *   alias used. The value is either a string in which case it's assumed to be
   *   a field on this handler's table; or it's an array in the form of
   *   @code array('table' => $tablename, 'field' => $fieldname) @endcode
   */
  public function add_additional_fields($fields = NULL) {
    if (!isset($fields)) {
      // Notice check.
      if (empty($this->additional_fields)) {
        return;
      }
      $fields = $this->additional_fields;
    }

    $group_params = array();
    if ($this->options['group_type'] != 'group') {
      $group_params = array(
        'function' => $this->options['group_type'],
      );
    }

    if (!empty($fields) && is_array($fields)) {
      foreach ($fields as $identifier => $info) {
        if (is_array($info)) {
          if (isset($info['table'])) {
            $table_alias = $this->query->ensure_table($info['table'], $this->relationship);
          }
          else {
            $table_alias = $this->table_alias;
          }

          if (empty($table_alias)) {
            $t_args = array(
              '@handler' => $this->definition['handler'],
              '@identifier' => $identifier,
              '@table' => $info['table'],
            );
            debug(t('Handler @handler tried to add additional_field @identifier but @table could not be added!', $t_args));
            $this->aliases[$identifier] = 'broken';
            continue;
          }

          $params = array();
          if (!empty($info['params'])) {
            $params = $info['params'];
          }

          $params += $group_params;
          $this->aliases[$identifier] = $this->query->add_field($table_alias, $info['field'], NULL, $params);
        }
        else {
          $this->aliases[$info] = $this->query->add_field($this->table_alias, $info, NULL, $group_params);
        }
      }
    }
  }
}
