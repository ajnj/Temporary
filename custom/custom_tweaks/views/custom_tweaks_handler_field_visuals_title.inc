<?php

class custom_tweaks_handler_field_visuals_title extends views_handler_field {

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
    $table = $this->additional_fields['title']['table'];
    $field = $this->additional_fields['title']['field'];

    $this->query->add_orderby($table, $field, $order);
  }

  function render($values) {
    $field_type_alias = $this->aliases['field_type'];
    $field_alias_alias = $this->aliases['field_alias'];
    $field_zcode_alias = $this->aliases['field_zcode'];
    $title_alias = $this->aliases['title'];
    $type = $values->$field_type_alias;
    $alias = $values->$field_alias_alias;
    $zcode = $values->$field_zcode_alias;
    $title = $values->$title_alias;

    preg_match('/^([a-z0-9]+_\w)_.+$/', $alias, $matches);

    if (empty($matches[1])) {
      return "[Error: URL of 'main' record couldn't be determined]";
    }

    $base_url = $matches[1];
    $introd_url = $base_url . '_h_1';
    $gall_url = $zcode;

    preg_match('/^.+#(.+)$/', $zcode, $matches);
    $other_url = !empty($matches[1]) ? "${base_url}_g#" . $matches[1] : "${base_url}_g";

    switch ($type) {
      case 'gall':
        $output = "<a href='/$gall_url'>$title</a> <a href='/$introd_url'>[Introd.]</a>";
        break;
      case 'tabx':
      case 'taby':
        $output = "<a href='/$alias'>$title</a> <a href='/$introd_url'>[Introd.]</a>";
        break;
      default:
        $output = "<a href='/$other_url'>$title</a> <a href='/$introd_url'>[Introd.]</a>";
    }

    return $output;
  }
}
