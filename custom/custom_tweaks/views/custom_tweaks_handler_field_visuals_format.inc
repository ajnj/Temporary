<?php

class custom_tweaks_handler_field_visuals_format extends views_handler_field {

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
    $this->additional_fields['field_charset'] = array(
      'table' => 'field_data_field_charset',
      'field' => 'field_charset_value',
    );
    $this->additional_fields['field_anchor'] = array(
      'table' => 'field_data_field_anchor',
      'field' => 'field_anchor_value',
    );
    $this->additional_fields['title'] = array(
      'table' => 'node',
      'field' => 'title',
    );
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function click_sort($order) {
    $table = $this->additional_fields['field_charset']['table'];
    $field = $this->additional_fields['field_charset']['field'];

    $this->query->add_orderby($table, $field, $order);
  }

  function render($values) {
    $field_type_alias = $this->aliases['field_type'];
    $field_alias_alias = $this->aliases['field_alias'];
    $field_zcode_alias = $this->aliases['field_zcode'];
    $title_alias = $this->aliases['title'];
    $field_charset = $this->aliases['field_charset'];
    $field_anchor = $this->aliases['field_anchor'];

    $type = $values->$field_type_alias;
    $alias = $values->$field_alias_alias;
    $zcode = $values->$field_zcode_alias;
    $title = $values->$title_alias;
    $anchor = $values->$field_anchor;
    $charset = $values->$field_charset;

    switch ($type) {
      case 'tabx':
      case 'taby':
        $output = "<a href='/$alias'>$charset</a>";
        break;
      default:
        $output = "<a href='$anchor'>$charset</a>";
    }

    return $output;
  }
}
