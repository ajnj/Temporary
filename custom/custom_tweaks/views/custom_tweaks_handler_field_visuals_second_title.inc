<?php

class custom_tweaks_handler_field_visuals_second_title extends views_handler_field {

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
    $this->additional_fields['field_zcode'] = array(
      'table' => 'field_data_field_zcode',
      'field' => 'field_zcode_value',
    );
    $this->additional_fields['field_title2'] = array(
      'table' => 'field_data_field_title2',
      'field' => 'field_title2_value',
    );
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function click_sort($order) {
    $table = $this->additional_fields['field_title2']['table'];
    $field = $this->additional_fields['field_title2']['field'];

    $this->query->add_orderby($table, $field, $order);
  }

  function render($values) {
    $field_type_alias = $this->aliases['field_type'];
    $field_alias_alias = $this->aliases['field_alias'];
    $field_zcode_alias = $this->aliases['field_zcode'];
    $title2_alias = $this->aliases['field_title2'];
    $type = $values->$field_type_alias;
    $alias = $values->$field_alias_alias;
    $zcode = $values->$field_zcode_alias;
    $title2 = $values->$title2_alias;

    preg_match('/^([a-z0-9]+_\w)_.+$/', $alias, $matches);

    if (empty($matches[1])) {
      return "[Error: URL of 'main' record couldn't be determined]";
    }

    switch ($type) {
      case 'gall':
        $output = $title2;
        break;
      case 'tabx':
      case 'taby':
        $output = "<a href='/$zcode'>$title2</a>";
        break;
      default:
        $other_url = preg_replace('/\*\d+$/', '', $alias);
        $output = "<a href='/$other_url'>$title2</a>";
    }

    return $output;
  }
}
