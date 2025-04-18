<?php

/**
 * @file
 * custom_features.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function custom_features_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'Visuals';
  $view->description = 'Titles of Kairos documents';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Visuals';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Visuals: images and animations in Kairos';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'views_calc';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_zcode' => 'field_zcode',
    'field_anchor' => 'field_anchor',
    'helios_visuals_title' => 'helios_visuals_title',
    'helios_visuals_second_title' => 'helios_visuals_second_title',
    'field_year' => 'field_year',
    'helios_visuals_format' => 'helios_visuals_format',
    'field_cittok' => 'field_cittok',
  );
  $handler->display->display_options['style_options']['default'] = 'field_cittok';
  $handler->display->display_options['style_options']['info'] = array(
    'field_zcode' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_anchor' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'helios_visuals_title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'helios_visuals_second_title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_year' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'helios_visuals_format' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_cittok' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 1,
      'calc' => array(
        'SUM' => 'SUM',
      ),
    ),
  );
  $handler->display->display_options['style_options']['detailed_values'] = '0';
  $handler->display->display_options['style_options']['precision'] = '0';
  /* Field: Content: zcode (hidden) */
  $handler->display->display_options['fields']['field_zcode']['id'] = 'field_zcode';
  $handler->display->display_options['fields']['field_zcode']['table'] = 'field_data_field_zcode';
  $handler->display->display_options['fields']['field_zcode']['field'] = 'field_zcode';
  $handler->display->display_options['fields']['field_zcode']['ui_name'] = 'Content: zcode (hidden)';
  $handler->display->display_options['fields']['field_zcode']['label'] = '';
  $handler->display->display_options['fields']['field_zcode']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_zcode']['element_label_colon'] = FALSE;
  /* Field: Content: anchor (hidden) */
  $handler->display->display_options['fields']['field_anchor']['id'] = 'field_anchor';
  $handler->display->display_options['fields']['field_anchor']['table'] = 'field_data_field_anchor';
  $handler->display->display_options['fields']['field_anchor']['field'] = 'field_anchor';
  $handler->display->display_options['fields']['field_anchor']['ui_name'] = 'Content: anchor (hidden)';
  $handler->display->display_options['fields']['field_anchor']['label'] = '';
  $handler->display->display_options['fields']['field_anchor']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_anchor']['element_label_colon'] = FALSE;
  /* Field: Content: Dynamic title for the visuals table. */
  $handler->display->display_options['fields']['helios_visuals_title']['id'] = 'helios_visuals_title';
  $handler->display->display_options['fields']['helios_visuals_title']['table'] = 'node';
  $handler->display->display_options['fields']['helios_visuals_title']['field'] = 'helios_visuals_title';
  $handler->display->display_options['fields']['helios_visuals_title']['label'] = 'Image / Animation / Table title';
  /* Field: Content: Dynamic second title for the visuals table. */
  $handler->display->display_options['fields']['helios_visuals_second_title']['id'] = 'helios_visuals_second_title';
  $handler->display->display_options['fields']['helios_visuals_second_title']['table'] = 'node';
  $handler->display->display_options['fields']['helios_visuals_second_title']['field'] = 'helios_visuals_second_title';
  $handler->display->display_options['fields']['helios_visuals_second_title']['label'] = 'Context for image / animation / table';
  /* Field: Content: year */
  $handler->display->display_options['fields']['field_year']['id'] = 'field_year';
  $handler->display->display_options['fields']['field_year']['table'] = 'field_data_field_year';
  $handler->display->display_options['fields']['field_year']['field'] = 'field_year';
  $handler->display->display_options['fields']['field_year']['label'] = 'Year';
  $handler->display->display_options['fields']['field_year']['element_label_colon'] = FALSE;
  /* Field: Content: Dynamic format field. */
  $handler->display->display_options['fields']['helios_visuals_format']['id'] = 'helios_visuals_format';
  $handler->display->display_options['fields']['helios_visuals_format']['table'] = 'node';
  $handler->display->display_options['fields']['helios_visuals_format']['field'] = 'helios_visuals_format';
  $handler->display->display_options['fields']['helios_visuals_format']['label'] = 'Format';
  /* Field: Content: cittok */
  $handler->display->display_options['fields']['field_cittok']['id'] = 'field_cittok';
  $handler->display->display_options['fields']['field_cittok']['table'] = 'field_data_field_cittok';
  $handler->display->display_options['fields']['field_cittok']['field'] = 'field_cittok';
  $handler->display->display_options['fields']['field_cittok']['label'] = 'Count';
  $handler->display->display_options['fields']['field_cittok']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['granularity'] = 'year';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  /* Filter criterion: Content: type (field_type) */
  $handler->display->display_options['filters']['field_type_value_1']['id'] = 'field_type_value_1';
  $handler->display->display_options['filters']['field_type_value_1']['table'] = 'field_data_field_type';
  $handler->display->display_options['filters']['field_type_value_1']['field'] = 'field_type_value';
  $handler->display->display_options['filters']['field_type_value_1']['group'] = 1;
  $handler->display->display_options['filters']['field_type_value_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_type_value_1']['expose']['operator_id'] = 'field_type_value_1_op';
  $handler->display->display_options['filters']['field_type_value_1']['expose']['label'] = 'type (field_type)';
  $handler->display->display_options['filters']['field_type_value_1']['expose']['operator'] = 'field_type_value_1_op';
  $handler->display->display_options['filters']['field_type_value_1']['expose']['identifier'] = 'field_type_value_1';
  $handler->display->display_options['filters']['field_type_value_1']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_type_value_1']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_type_value_1']['group_info']['label'] = 'Type';
  $handler->display->display_options['filters']['field_type_value_1']['group_info']['identifier'] = 'field_type_value_1';
  $handler->display->display_options['filters']['field_type_value_1']['group_info']['optional'] = FALSE;
  $handler->display->display_options['filters']['field_type_value_1']['group_info']['widget'] = 'radios';
  $handler->display->display_options['filters']['field_type_value_1']['group_info']['default_group'] = '3';
  $handler->display->display_options['filters']['field_type_value_1']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Images (static)',
      'operator' => 'or',
      'value' => array(
        'imag' => 'imag',
      ),
    ),
    2 => array(
      'title' => 'Animations',
      'operator' => 'or',
      'value' => array(
        'anim' => 'anim',
      ),
    ),
    3 => array(
      'title' => 'Galleries',
      'operator' => 'or',
      'value' => array(
        'gall' => 'gall',
      ),
    ),
    4 => array(
      'title' => 'Tables (with images)',
      'operator' => 'or',
      'value' => array(
        'tabx' => 'tabx',
      ),
    ),
    5 => array(
      'title' => 'Tables (w/o images)',
      'operator' => 'or',
      'value' => array(
        'taby' => 'taby',
      ),
    ),
    6 => array(
      'title' => 'All',
      'operator' => 'or',
      'value' => array(
        'anim' => 'anim',
        'imag' => 'imag',
        'gall' => 'gall',
      ),
    ),
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 2;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'data' => 'data',
  );
  $handler->display->display_options['filters']['type']['group'] = 2;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 2;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['description'] = 'Kairos document title';
  $handler->display->display_options['filters']['title']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    3 => 0,
    1 => 0,
  );
  $handler->display->display_options['filters']['title']['group_info']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['group_info']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['group_info']['multiple'] = TRUE;
  $handler->display->display_options['filters']['title']['group_info']['group_items'] = array(
    1 => array(
      'title' => '',
      'operator' => 'contains',
      'value' => '',
    ),
    2 => array(
      'title' => '',
      'operator' => 'contains',
      'value' => '',
    ),
    3 => array(
      'title' => '',
      'operator' => 'contains',
      'value' => '',
    ),
  );
  /* Filter criterion: Content: year (field_year) */
  $handler->display->display_options['filters']['field_year_value']['id'] = 'field_year_value';
  $handler->display->display_options['filters']['field_year_value']['table'] = 'field_data_field_year';
  $handler->display->display_options['filters']['field_year_value']['field'] = 'field_year_value';
  $handler->display->display_options['filters']['field_year_value']['group'] = 2;
  $handler->display->display_options['filters']['field_year_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_year_value']['expose']['operator_id'] = 'field_year_value_op';
  $handler->display->display_options['filters']['field_year_value']['expose']['label'] = 'Year';
  $handler->display->display_options['filters']['field_year_value']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_year_value']['expose']['operator'] = 'field_year_value_op';
  $handler->display->display_options['filters']['field_year_value']['expose']['identifier'] = 'field_year_value';
  $handler->display->display_options['filters']['field_year_value']['expose']['remember_roles'] = array(
    2 => '2',
    3 => 0,
    1 => 0,
  );
  /* Filter criterion: Content: cittok (field_cittok) */
  $handler->display->display_options['filters']['field_cittok_value']['id'] = 'field_cittok_value';
  $handler->display->display_options['filters']['field_cittok_value']['table'] = 'field_data_field_cittok';
  $handler->display->display_options['filters']['field_cittok_value']['field'] = 'field_cittok_value';
  $handler->display->display_options['filters']['field_cittok_value']['operator'] = '<';
  $handler->display->display_options['filters']['field_cittok_value']['group'] = 2;
  $handler->display->display_options['filters']['field_cittok_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_cittok_value']['expose']['operator_id'] = 'field_cittok_value_op';
  $handler->display->display_options['filters']['field_cittok_value']['expose']['label'] = 'Citations to Kairos';
  $handler->display->display_options['filters']['field_cittok_value']['expose']['description'] = 'Number of Kairos documents cited';
  $handler->display->display_options['filters']['field_cittok_value']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_cittok_value']['expose']['operator'] = 'field_cittok_value_op';
  $handler->display->display_options['filters']['field_cittok_value']['expose']['identifier'] = 'field_cittok_value';
  $handler->display->display_options['filters']['field_cittok_value']['expose']['remember_roles'] = array(
    2 => '2',
    3 => 0,
    1 => 0,
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title_1']['id'] = 'title_1';
  $handler->display->display_options['filters']['title_1']['table'] = 'node';
  $handler->display->display_options['filters']['title_1']['field'] = 'title';
  $handler->display->display_options['filters']['title_1']['operator'] = 'longerthan';
  $handler->display->display_options['filters']['title_1']['value'] = '3';
  $handler->display->display_options['filters']['title_1']['group'] = 2;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'visuals';
  $handler->display->display_options['menu']['title'] = 'Document titles (new)';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['Visuals'] = array(
    t('Master'),
    t('Visuals: images and animations in Kairos'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Image / Animation / Table title'),
    t('Context for image / animation / table'),
    t('Year'),
    t('Format'),
    t('Count'),
    t('type (field_type)'),
    t('Type'),
    t('Title'),
    t('Kairos document title'),
    t('Citations to Kairos'),
    t('Number of Kairos documents cited'),
    t('Page'),
  );
  $export['Visuals'] = $view;

  $view = new view();
  $view->name = 'all_nodes';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'All nodes';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'All nodes';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'type' => 'type',
    'field_type' => 'field_type',
    'path' => 'path',
    'field_wcode' => 'field_wcode',
    'field_partno' => 'field_partno',
    'field_themes' => 'field_themes',
    'field_title2' => 'field_title2',
    'field_keywords' => 'field_keywords',
    'field_description' => 'field_description',
    'field_author' => 'field_author',
    'field_year' => 'field_year',
    'field_month' => 'field_month',
    'field_day' => 'field_day',
    'field_completion' => 'field_completion',
    'field_anchor' => 'field_anchor',
    'field_warnings' => 'field_warnings',
    'field_charset' => 'field_charset',
    'field_cittok' => 'field_cittok',
    'field_citfrk' => 'field_citfrk',
    'field_xcode' => 'field_xcode',
    'field_ycode' => 'field_ycode',
    'field_zcode' => 'field_zcode',
    'body' => 'body',
    'changed' => 'changed',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = 'changed';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'path' => array(
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_wcode' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_partno' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_themes' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_title2' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_keywords' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_description' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_author' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_year' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_month' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_day' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_completion' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_anchor' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_warnings' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_charset' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_cittok' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_citfrk' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_xcode' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_ycode' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_zcode' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = 'Content';
  /* Field: Content: type */
  $handler->display->display_options['fields']['field_type']['id'] = 'field_type';
  $handler->display->display_options['fields']['field_type']['table'] = 'field_data_field_type';
  $handler->display->display_options['fields']['field_type']['field'] = 'field_type';
  $handler->display->display_options['fields']['field_type']['label'] = 'Data';
  $handler->display->display_options['fields']['field_type']['type'] = 'text_default';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  /* Field: Content: wcode */
  $handler->display->display_options['fields']['field_wcode']['id'] = 'field_wcode';
  $handler->display->display_options['fields']['field_wcode']['table'] = 'field_data_field_wcode';
  $handler->display->display_options['fields']['field_wcode']['field'] = 'field_wcode';
  $handler->display->display_options['fields']['field_wcode']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Content: partno */
  $handler->display->display_options['fields']['field_partno']['id'] = 'field_partno';
  $handler->display->display_options['fields']['field_partno']['table'] = 'field_data_field_partno';
  $handler->display->display_options['fields']['field_partno']['field'] = 'field_partno';
  /* Field: Content: themes */
  $handler->display->display_options['fields']['field_themes']['id'] = 'field_themes';
  $handler->display->display_options['fields']['field_themes']['table'] = 'field_data_field_themes';
  $handler->display->display_options['fields']['field_themes']['field'] = 'field_themes';
  /* Field: Content: title2 */
  $handler->display->display_options['fields']['field_title2']['id'] = 'field_title2';
  $handler->display->display_options['fields']['field_title2']['table'] = 'field_data_field_title2';
  $handler->display->display_options['fields']['field_title2']['field'] = 'field_title2';
  /* Field: Content: keywords */
  $handler->display->display_options['fields']['field_keywords']['id'] = 'field_keywords';
  $handler->display->display_options['fields']['field_keywords']['table'] = 'field_data_field_keywords';
  $handler->display->display_options['fields']['field_keywords']['field'] = 'field_keywords';
  /* Field: Content: description */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  /* Field: Content: author */
  $handler->display->display_options['fields']['field_author']['id'] = 'field_author';
  $handler->display->display_options['fields']['field_author']['table'] = 'field_data_field_author';
  $handler->display->display_options['fields']['field_author']['field'] = 'field_author';
  /* Field: Content: year */
  $handler->display->display_options['fields']['field_year']['id'] = 'field_year';
  $handler->display->display_options['fields']['field_year']['table'] = 'field_data_field_year';
  $handler->display->display_options['fields']['field_year']['field'] = 'field_year';
  $handler->display->display_options['fields']['field_year']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_year']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Content: month */
  $handler->display->display_options['fields']['field_month']['id'] = 'field_month';
  $handler->display->display_options['fields']['field_month']['table'] = 'field_data_field_month';
  $handler->display->display_options['fields']['field_month']['field'] = 'field_month';
  $handler->display->display_options['fields']['field_month']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_month']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Content: day */
  $handler->display->display_options['fields']['field_day']['id'] = 'field_day';
  $handler->display->display_options['fields']['field_day']['table'] = 'field_data_field_day';
  $handler->display->display_options['fields']['field_day']['field'] = 'field_day';
  $handler->display->display_options['fields']['field_day']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_day']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Content: completion */
  $handler->display->display_options['fields']['field_completion']['id'] = 'field_completion';
  $handler->display->display_options['fields']['field_completion']['table'] = 'field_data_field_completion';
  $handler->display->display_options['fields']['field_completion']['field'] = 'field_completion';
  /* Field: Content: anchor */
  $handler->display->display_options['fields']['field_anchor']['id'] = 'field_anchor';
  $handler->display->display_options['fields']['field_anchor']['table'] = 'field_data_field_anchor';
  $handler->display->display_options['fields']['field_anchor']['field'] = 'field_anchor';
  /* Field: Content: warnings */
  $handler->display->display_options['fields']['field_warnings']['id'] = 'field_warnings';
  $handler->display->display_options['fields']['field_warnings']['table'] = 'field_data_field_warnings';
  $handler->display->display_options['fields']['field_warnings']['field'] = 'field_warnings';
  /* Field: Content: charset */
  $handler->display->display_options['fields']['field_charset']['id'] = 'field_charset';
  $handler->display->display_options['fields']['field_charset']['table'] = 'field_data_field_charset';
  $handler->display->display_options['fields']['field_charset']['field'] = 'field_charset';
  /* Field: Content: cittok */
  $handler->display->display_options['fields']['field_cittok']['id'] = 'field_cittok';
  $handler->display->display_options['fields']['field_cittok']['table'] = 'field_data_field_cittok';
  $handler->display->display_options['fields']['field_cittok']['field'] = 'field_cittok';
  $handler->display->display_options['fields']['field_cittok']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cittok']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Content: citfrk */
  $handler->display->display_options['fields']['field_citfrk']['id'] = 'field_citfrk';
  $handler->display->display_options['fields']['field_citfrk']['table'] = 'field_data_field_citfrk';
  $handler->display->display_options['fields']['field_citfrk']['field'] = 'field_citfrk';
  $handler->display->display_options['fields']['field_citfrk']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_citfrk']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Content: xcode */
  $handler->display->display_options['fields']['field_xcode']['id'] = 'field_xcode';
  $handler->display->display_options['fields']['field_xcode']['table'] = 'field_data_field_xcode';
  $handler->display->display_options['fields']['field_xcode']['field'] = 'field_xcode';
  $handler->display->display_options['fields']['field_xcode']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_xcode']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Content: ycode */
  $handler->display->display_options['fields']['field_ycode']['id'] = 'field_ycode';
  $handler->display->display_options['fields']['field_ycode']['table'] = 'field_data_field_ycode';
  $handler->display->display_options['fields']['field_ycode']['field'] = 'field_ycode';
  $handler->display->display_options['fields']['field_ycode']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ycode']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Content: zcode */
  $handler->display->display_options['fields']['field_zcode']['id'] = 'field_zcode';
  $handler->display->display_options['fields']['field_zcode']['table'] = 'field_data_field_zcode';
  $handler->display->display_options['fields']['field_zcode']['field'] = 'field_zcode';
  $handler->display->display_options['fields']['field_zcode']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'body';
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '100',
  );
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'Y-m-d H:i:s';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    3 => 0,
    1 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    3 => 0,
    1 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/helios/nodes';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'All nodes';
  $handler->display->display_options['menu']['weight'] = '10';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['all_nodes'] = array(
    t('Master'),
    t('All nodes'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Displaying @start - @end of @total'),
    t('Title'),
    t('Content'),
    t('Data'),
    t('Path'),
    t('wcode'),
    t('partno'),
    t('themes'),
    t('title2'),
    t('keywords'),
    t('description'),
    t('author'),
    t('year'),
    t('month'),
    t('day'),
    t('completion'),
    t('anchor'),
    t('warnings'),
    t('charset'),
    t('cittok'),
    t('citfrk'),
    t('xcode'),
    t('ycode'),
    t('zcode'),
    t('body'),
    t('Updated'),
    t('Type'),
    t('Page'),
  );
  $export['all_nodes'] = $view;

  $view = new view();
  $view->name = 'authors';
  $view->description = 'Authors of publications cited in Kairos documents';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'authors';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Authors cited by Kairos documents';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'views_calc';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_xcode' => 'field_xcode',
    'field_ycode' => 'field_ycode',
    'field_citfrk' => 'field_citfrk',
  );
  $handler->display->display_options['style_options']['default'] = 'field_ycode';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_xcode' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 1,
      'calc' => array(
        'SUM' => 'SUM',
      ),
    ),
    'field_ycode' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 1,
      'calc' => array(
        'SUM' => 'SUM',
      ),
    ),
    'field_citfrk' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 1,
      'calc' => array(
        'SUM' => 'SUM',
      ),
    ),
  );
  $handler->display->display_options['style_options']['detailed_values'] = '0';
  $handler->display->display_options['style_options']['precision'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Author name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: xcode */
  $handler->display->display_options['fields']['field_xcode']['id'] = 'field_xcode';
  $handler->display->display_options['fields']['field_xcode']['table'] = 'field_data_field_xcode';
  $handler->display->display_options['fields']['field_xcode']['field'] = 'field_xcode';
  $handler->display->display_options['fields']['field_xcode']['label'] = 'Author docs';
  $handler->display->display_options['fields']['field_xcode']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_xcode']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Content: ycode */
  $handler->display->display_options['fields']['field_ycode']['id'] = 'field_ycode';
  $handler->display->display_options['fields']['field_ycode']['table'] = 'field_data_field_ycode';
  $handler->display->display_options['fields']['field_ycode']['field'] = 'field_ycode';
  $handler->display->display_options['fields']['field_ycode']['label'] = 'Citations by Kairos';
  $handler->display->display_options['fields']['field_ycode']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Content: citfrk */
  $handler->display->display_options['fields']['field_citfrk']['id'] = 'field_citfrk';
  $handler->display->display_options['fields']['field_citfrk']['table'] = 'field_data_field_citfrk';
  $handler->display->display_options['fields']['field_citfrk']['field'] = 'field_citfrk';
  $handler->display->display_options['fields']['field_citfrk']['label'] = 'Refs';
  $handler->display->display_options['fields']['field_citfrk']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['granularity'] = 'year';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: type (field_type) */
  $handler->display->display_options['filters']['field_type_value']['id'] = 'field_type_value';
  $handler->display->display_options['filters']['field_type_value']['table'] = 'field_data_field_type';
  $handler->display->display_options['filters']['field_type_value']['field'] = 'field_type_value';
  $handler->display->display_options['filters']['field_type_value']['value'] = array(
    'author' => 'author',
  );
  $handler->display->display_options['filters']['field_type_value']['group'] = 1;
  $handler->display->display_options['filters']['field_type_value']['expose']['operator_id'] = 'field_type_value_op';
  $handler->display->display_options['filters']['field_type_value']['expose']['label'] = 'Author name';
  $handler->display->display_options['filters']['field_type_value']['expose']['operator'] = 'field_type_value_op';
  $handler->display->display_options['filters']['field_type_value']['expose']['identifier'] = 'field_type_value';
  $handler->display->display_options['filters']['field_type_value']['expose']['remember_roles'] = array(
    2 => '2',
    3 => 0,
    1 => 0,
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Author name';
  $handler->display->display_options['filters']['title']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    3 => 0,
    1 => 0,
  );
  /* Filter criterion: Content: ycode (field_ycode) */
  $handler->display->display_options['filters']['field_ycode_value']['id'] = 'field_ycode_value';
  $handler->display->display_options['filters']['field_ycode_value']['table'] = 'field_data_field_ycode';
  $handler->display->display_options['filters']['field_ycode_value']['field'] = 'field_ycode_value';
  $handler->display->display_options['filters']['field_ycode_value']['operator'] = '<';
  $handler->display->display_options['filters']['field_ycode_value']['group'] = 1;
  $handler->display->display_options['filters']['field_ycode_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_ycode_value']['expose']['operator_id'] = 'field_ycode_value_op';
  $handler->display->display_options['filters']['field_ycode_value']['expose']['label'] = 'Citations by Kairos';
  $handler->display->display_options['filters']['field_ycode_value']['expose']['description'] = 'Number of Kairos documents citing';
  $handler->display->display_options['filters']['field_ycode_value']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_ycode_value']['expose']['operator'] = 'field_ycode_value_op';
  $handler->display->display_options['filters']['field_ycode_value']['expose']['identifier'] = 'field_ycode_value';
  $handler->display->display_options['filters']['field_ycode_value']['expose']['remember_roles'] = array(
    2 => '2',
    3 => 0,
    1 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'authors';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Authors cited (new)';
  $handler->display->display_options['menu']['description'] = 'Authors of publications cited in Kairos documents';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['authors'] = array(
    t('Master'),
    t('Authors cited by Kairos documents'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Author name'),
    t('Author docs'),
    t('Citations by Kairos'),
    t('Refs'),
    t('Number of Kairos documents citing'),
    t('Page'),
  );
  $export['authors'] = $view;

  $view = new view();
  $view->name = 'document_titles_test3';
  $view->description = 'Authors of publications cited in Kairos documents';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Authors cited';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Document titles test3';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['order'] = 'DESC';
  $handler->display->display_options['sorts']['title']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'Title';
  /* Contextual filter: Content: partno (field_partno) */
  $handler->display->display_options['arguments']['field_partno_value']['id'] = 'field_partno_value';
  $handler->display->display_options['arguments']['field_partno_value']['table'] = 'field_data_field_partno';
  $handler->display->display_options['arguments']['field_partno_value']['field'] = 'field_partno_value';
  $handler->display->display_options['arguments']['field_partno_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_partno_value']['summary']['format'] = 'default_summary';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'data' => 'data',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Document titles';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_calc';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_title2' => 'field_title2',
    'field_partno' => 'field_partno',
    'field_year' => 'field_year',
    'field_type' => 'field_type',
    'field_citfrk' => 'field_citfrk',
  );
  $handler->display->display_options['style_options']['default'] = 'field_citfrk';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_title2' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_partno' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_year' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_citfrk' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 1,
      'calc' => array(
        'SUM' => 'SUM',
      ),
    ),
  );
  $handler->display->display_options['style_options']['detailed_values'] = '0';
  $handler->display->display_options['style_options']['precision'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: title2 */
  $handler->display->display_options['fields']['field_title2']['id'] = 'field_title2';
  $handler->display->display_options['fields']['field_title2']['table'] = 'field_data_field_title2';
  $handler->display->display_options['fields']['field_title2']['field'] = 'field_title2';
  $handler->display->display_options['fields']['field_title2']['label'] = 'Secondary title';
  $handler->display->display_options['fields']['field_title2']['element_label_colon'] = FALSE;
  /* Field: Content: partno */
  $handler->display->display_options['fields']['field_partno']['id'] = 'field_partno';
  $handler->display->display_options['fields']['field_partno']['table'] = 'field_data_field_partno';
  $handler->display->display_options['fields']['field_partno']['field'] = 'field_partno';
  $handler->display->display_options['fields']['field_partno']['label'] = 'Part';
  $handler->display->display_options['fields']['field_partno']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: year */
  $handler->display->display_options['fields']['field_year']['id'] = 'field_year';
  $handler->display->display_options['fields']['field_year']['table'] = 'field_data_field_year';
  $handler->display->display_options['fields']['field_year']['field'] = 'field_year';
  $handler->display->display_options['fields']['field_year']['label'] = 'Year';
  $handler->display->display_options['fields']['field_year']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_year']['type'] = 'text_default';
  /* Field: Content: type */
  $handler->display->display_options['fields']['field_type']['id'] = 'field_type';
  $handler->display->display_options['fields']['field_type']['table'] = 'field_data_field_type';
  $handler->display->display_options['fields']['field_type']['field'] = 'field_type';
  $handler->display->display_options['fields']['field_type']['label'] = 'Type';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'data' => 'data',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    3 => 0,
    1 => 0,
  );
  /* Filter criterion: Content: year (field_year) */
  $handler->display->display_options['filters']['field_year_value']['id'] = 'field_year_value';
  $handler->display->display_options['filters']['field_year_value']['table'] = 'field_data_field_year';
  $handler->display->display_options['filters']['field_year_value']['field'] = 'field_year_value';
  $handler->display->display_options['filters']['field_year_value']['group'] = 1;
  $handler->display->display_options['filters']['field_year_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_year_value']['expose']['operator_id'] = 'field_year_value_op';
  $handler->display->display_options['filters']['field_year_value']['expose']['label'] = 'Year';
  $handler->display->display_options['filters']['field_year_value']['expose']['description'] = 'Year of publication';
  $handler->display->display_options['filters']['field_year_value']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_year_value']['expose']['operator'] = 'field_year_value_op';
  $handler->display->display_options['filters']['field_year_value']['expose']['identifier'] = 'field_year_value';
  $handler->display->display_options['filters']['field_year_value']['expose']['remember_roles'] = array(
    2 => '2',
    3 => 0,
    1 => 0,
  );
  /* Filter criterion: Content: type (field_type) */
  $handler->display->display_options['filters']['field_type_value']['id'] = 'field_type_value';
  $handler->display->display_options['filters']['field_type_value']['table'] = 'field_data_field_type';
  $handler->display->display_options['filters']['field_type_value']['field'] = 'field_type_value';
  $handler->display->display_options['filters']['field_type_value']['value'] = array(
    'author' => 'author',
    'dmain' => 'dmain',
    'dpart' => 'dpart',
  );
  $handler->display->display_options['filters']['field_type_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_type_value']['expose']['operator_id'] = 'field_type_value_op';
  $handler->display->display_options['filters']['field_type_value']['expose']['label'] = 'type (field_type)';
  $handler->display->display_options['filters']['field_type_value']['expose']['operator'] = 'field_type_value_op';
  $handler->display->display_options['filters']['field_type_value']['expose']['identifier'] = 'field_type_value';
  $handler->display->display_options['filters']['field_type_value']['expose']['remember_roles'] = array(
    2 => '2',
    3 => 0,
    1 => 0,
  );
  $handler->display->display_options['filters']['field_type_value']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_type_value']['group_info']['label'] = 'type (field_type)';
  $handler->display->display_options['filters']['field_type_value']['group_info']['identifier'] = 'field_type_value';
  $handler->display->display_options['filters']['field_type_value']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Main',
      'operator' => 'or',
      'value' => array(
        'dmain' => 'dmain',
      ),
    ),
    2 => array(
      'title' => 'Part',
      'operator' => 'or',
      'value' => array(
        'dpart' => 'dpart',
      ),
    ),
    3 => array(
      'title' => 'Encyc',
      'operator' => 'or',
      'value' => array(
        'encyc' => 'encyc',
      ),
    ),
    4 => array(
      'title' => 'Civil',
      'operator' => 'or',
      'value' => array(
        'cmain' => 'cmain',
        'cpart' => 'cpart',
      ),
    ),
  );
  /* Filter criterion: Content: anchor (field_anchor) */
  $handler->display->display_options['filters']['field_anchor_value']['id'] = 'field_anchor_value';
  $handler->display->display_options['filters']['field_anchor_value']['table'] = 'field_data_field_anchor';
  $handler->display->display_options['filters']['field_anchor_value']['field'] = 'field_anchor_value';
  $handler->display->display_options['filters']['field_anchor_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_anchor_value']['value'] = '/ching/';
  $handler->display->display_options['path'] = 'document-titles';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Document titles';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Authors cited';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_title2' => 'field_title2',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_title2' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Author';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: title2 */
  $handler->display->display_options['fields']['field_title2']['id'] = 'field_title2';
  $handler->display->display_options['fields']['field_title2']['table'] = 'field_data_field_title2';
  $handler->display->display_options['fields']['field_title2']['field'] = 'field_title2';
  $handler->display->display_options['fields']['field_title2']['label'] = 'Secondary title';
  $handler->display->display_options['fields']['field_title2']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'data' => 'data',
  );
  /* Filter criterion: Content: type (field_type) */
  $handler->display->display_options['filters']['field_type_value']['id'] = 'field_type_value';
  $handler->display->display_options['filters']['field_type_value']['table'] = 'field_data_field_type';
  $handler->display->display_options['filters']['field_type_value']['field'] = 'field_type_value';
  $handler->display->display_options['filters']['field_type_value']['value'] = array(
    'author' => 'author',
  );
  $handler->display->display_options['filters']['field_type_value']['expose']['operator_id'] = 'field_type_value_op';
  $handler->display->display_options['filters']['field_type_value']['expose']['label'] = 'type (field_type)';
  $handler->display->display_options['filters']['field_type_value']['expose']['operator'] = 'field_type_value_op';
  $handler->display->display_options['filters']['field_type_value']['expose']['identifier'] = 'field_type_value';
  $handler->display->display_options['path'] = 'authors-cited';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Authors cited';
  $handler->display->display_options['menu']['description'] = 'Authors of publications cited in Kairos documents';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Page 2 */
  $handler = $view->new_display('page', 'Page 2', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'References';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'title_1' => 'title_1',
    'field_year' => 'field_year',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_year' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['label'] = 'Title of Kairos document with references';
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  /* Field: Content: year */
  $handler->display->display_options['fields']['field_year']['id'] = 'field_year';
  $handler->display->display_options['fields']['field_year']['table'] = 'field_data_field_year';
  $handler->display->display_options['fields']['field_year']['field'] = 'field_year';
  $handler->display->display_options['fields']['field_year']['label'] = 'Year';
  $handler->display->display_options['fields']['field_year']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_year']['type'] = 'text_default';
  /* Field: Content: title2 */
  $handler->display->display_options['fields']['field_title2']['id'] = 'field_title2';
  $handler->display->display_options['fields']['field_title2']['table'] = 'field_data_field_title2';
  $handler->display->display_options['fields']['field_title2']['field'] = 'field_title2';
  $handler->display->display_options['fields']['field_title2']['label'] = 'Secondary title';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'data' => 'data',
  );
  /* Filter criterion: Content: title2 (field_title2) */
  $handler->display->display_options['filters']['field_title2_value']['id'] = 'field_title2_value';
  $handler->display->display_options['filters']['field_title2_value']['table'] = 'field_data_field_title2';
  $handler->display->display_options['filters']['field_title2_value']['field'] = 'field_title2_value';
  $handler->display->display_options['filters']['field_title2_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_title2_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_title2_value']['expose']['operator_id'] = 'field_title2_value_op';
  $handler->display->display_options['filters']['field_title2_value']['expose']['label'] = 'Secondary title';
  $handler->display->display_options['filters']['field_title2_value']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_title2_value']['expose']['operator'] = 'field_title2_value_op';
  $handler->display->display_options['filters']['field_title2_value']['expose']['identifier'] = 'field_title2_value';
  $handler->display->display_options['filters']['field_title2_value']['expose']['remember_roles'] = array(
    2 => '2',
    3 => 0,
    1 => 0,
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    3 => 0,
    1 => 0,
  );
  $handler->display->display_options['path'] = 'refs';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'References cited';
  $handler->display->display_options['menu']['description'] = 'External references cited in Kairos documents';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['document_titles_test3'] = array(
    t('Master'),
    t('Document titles test3'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Title'),
    t('All'),
    t('Page'),
    t('Document titles'),
    t('Secondary title'),
    t('Part'),
    t('Year'),
    t('Type'),
    t('Year of publication'),
    t('type (field_type)'),
    t('Authors cited'),
    t('Author'),
    t('Page 2'),
    t('References'),
    t('Title of Kairos document with references'),
  );
  $export['document_titles_test3'] = $view;

  $view = new view();
  $view->name = 'references';
  $view->description = 'External documents cited from Kairos';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'references';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'References cited from Kairos';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'views_calc';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_title2' => 'field_title2',
    'field_cittok' => 'field_cittok',
    'field_xcode' => 'field_xcode',
    'field_year' => 'field_year',
  );
  $handler->display->display_options['style_options']['default'] = 'field_cittok';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_title2' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_cittok' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 1,
      'calc' => array(
        'SUM' => 'SUM',
      ),
    ),
    'field_xcode' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 1,
      'calc' => array(
        'SUM' => 'SUM',
      ),
    ),
    'field_year' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
  );
  $handler->display->display_options['style_options']['detailed_values'] = '0';
  $handler->display->display_options['style_options']['precision'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: title2 */
  $handler->display->display_options['fields']['field_title2']['id'] = 'field_title2';
  $handler->display->display_options['fields']['field_title2']['table'] = 'field_data_field_title2';
  $handler->display->display_options['fields']['field_title2']['field'] = 'field_title2';
  $handler->display->display_options['fields']['field_title2']['label'] = 'Secondary title';
  /* Field: Content: cittok */
  $handler->display->display_options['fields']['field_cittok']['id'] = 'field_cittok';
  $handler->display->display_options['fields']['field_cittok']['table'] = 'field_data_field_cittok';
  $handler->display->display_options['fields']['field_cittok']['field'] = 'field_cittok';
  $handler->display->display_options['fields']['field_cittok']['label'] = 'To Kairos';
  $handler->display->display_options['fields']['field_cittok']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: xcode */
  $handler->display->display_options['fields']['field_xcode']['id'] = 'field_xcode';
  $handler->display->display_options['fields']['field_xcode']['table'] = 'field_data_field_xcode';
  $handler->display->display_options['fields']['field_xcode']['field'] = 'field_xcode';
  $handler->display->display_options['fields']['field_xcode']['label'] = 'By Kairos';
  $handler->display->display_options['fields']['field_xcode']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: year */
  $handler->display->display_options['fields']['field_year']['id'] = 'field_year';
  $handler->display->display_options['fields']['field_year']['table'] = 'field_data_field_year';
  $handler->display->display_options['fields']['field_year']['field'] = 'field_year';
  $handler->display->display_options['fields']['field_year']['label'] = 'Year';
  $handler->display->display_options['fields']['field_year']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_year']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'data' => 'data',
  );
  /* Filter criterion: Content: type (field_type) */
  $handler->display->display_options['filters']['field_type_value']['id'] = 'field_type_value';
  $handler->display->display_options['filters']['field_type_value']['table'] = 'field_data_field_type';
  $handler->display->display_options['filters']['field_type_value']['field'] = 'field_type_value';
  $handler->display->display_options['filters']['field_type_value']['value'] = array(
    'refs' => 'refs',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'references';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'references (new)';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $translatables['references'] = array(
    t('Master'),
    t('References cited from Kairos'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Title'),
    t('Secondary title'),
    t('To Kairos'),
    t('By Kairos'),
    t('Year'),
    t('Page'),
  );
  $export['references'] = $view;

  $view = new view();
  $view->name = 'titles';
  $view->description = 'Titles of Kairos documents';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Titles';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Titles of Kairos documents';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'views_calc';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_title2' => 'field_title2',
    'field_year' => 'field_year',
    'field_cittok' => 'field_cittok',
    'field_partno' => 'field_partno',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_title2' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_year' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_cittok' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 1,
      'calc' => array(
        'SUM' => 'SUM',
      ),
    ),
    'field_partno' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 1,
      'calc' => array(
        'SUM' => 'SUM',
      ),
    ),
  );
  $handler->display->display_options['style_options']['detailed_values'] = '0';
  $handler->display->display_options['style_options']['precision'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: title2 */
  $handler->display->display_options['fields']['field_title2']['id'] = 'field_title2';
  $handler->display->display_options['fields']['field_title2']['table'] = 'field_data_field_title2';
  $handler->display->display_options['fields']['field_title2']['field'] = 'field_title2';
  $handler->display->display_options['fields']['field_title2']['label'] = 'Secondary title';
  /* Field: Content: year */
  $handler->display->display_options['fields']['field_year']['id'] = 'field_year';
  $handler->display->display_options['fields']['field_year']['table'] = 'field_data_field_year';
  $handler->display->display_options['fields']['field_year']['field'] = 'field_year';
  $handler->display->display_options['fields']['field_year']['label'] = 'Year';
  $handler->display->display_options['fields']['field_year']['element_label_colon'] = FALSE;
  /* Field: Content: cittok */
  $handler->display->display_options['fields']['field_cittok']['id'] = 'field_cittok';
  $handler->display->display_options['fields']['field_cittok']['table'] = 'field_data_field_cittok';
  $handler->display->display_options['fields']['field_cittok']['field'] = 'field_cittok';
  $handler->display->display_options['fields']['field_cittok']['label'] = 'Citations to Kairos';
  $handler->display->display_options['fields']['field_cittok']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: partno */
  $handler->display->display_options['fields']['field_partno']['id'] = 'field_partno';
  $handler->display->display_options['fields']['field_partno']['table'] = 'field_data_field_partno';
  $handler->display->display_options['fields']['field_partno']['field'] = 'field_partno';
  $handler->display->display_options['fields']['field_partno']['label'] = 'Partno';
  $handler->display->display_options['fields']['field_partno']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['granularity'] = 'year';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'OR',
    2 => 'AND',
  );
  /* Filter criterion: Content: Helios: Documents filter */
  $handler->display->display_options['filters']['helios_documents_filter']['id'] = 'helios_documents_filter';
  $handler->display->display_options['filters']['helios_documents_filter']['table'] = 'node';
  $handler->display->display_options['filters']['helios_documents_filter']['field'] = 'helios_documents_filter';
  $handler->display->display_options['filters']['helios_documents_filter']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['helios_documents_filter']['group'] = 1;
  $handler->display->display_options['filters']['helios_documents_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['helios_documents_filter']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['helios_documents_filter']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['helios_documents_filter']['expose']['operator'] = 'helios_documents_filter_op';
  $handler->display->display_options['filters']['helios_documents_filter']['expose']['identifier'] = 'helios_documents_filter';
  $handler->display->display_options['filters']['helios_documents_filter']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['helios_documents_filter']['expose']['remember_roles'] = array(
    2 => '2',
    3 => 0,
    1 => 0,
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 2;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'data' => 'data',
  );
  $handler->display->display_options['filters']['type']['group'] = 2;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 2;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['description'] = 'Kairos document title';
  $handler->display->display_options['filters']['title']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    3 => 0,
    1 => 0,
  );
  $handler->display->display_options['filters']['title']['group_info']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['group_info']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['group_info']['multiple'] = TRUE;
  $handler->display->display_options['filters']['title']['group_info']['group_items'] = array(
    1 => array(
      'title' => '',
      'operator' => 'contains',
      'value' => '',
    ),
    2 => array(
      'title' => '',
      'operator' => 'contains',
      'value' => '',
    ),
    3 => array(
      'title' => '',
      'operator' => 'contains',
      'value' => '',
    ),
  );
  /* Filter criterion: Content: year (field_year) */
  $handler->display->display_options['filters']['field_year_value']['id'] = 'field_year_value';
  $handler->display->display_options['filters']['field_year_value']['table'] = 'field_data_field_year';
  $handler->display->display_options['filters']['field_year_value']['field'] = 'field_year_value';
  $handler->display->display_options['filters']['field_year_value']['group'] = 2;
  $handler->display->display_options['filters']['field_year_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_year_value']['expose']['operator_id'] = 'field_year_value_op';
  $handler->display->display_options['filters']['field_year_value']['expose']['label'] = 'Year';
  $handler->display->display_options['filters']['field_year_value']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_year_value']['expose']['operator'] = 'field_year_value_op';
  $handler->display->display_options['filters']['field_year_value']['expose']['identifier'] = 'field_year_value';
  $handler->display->display_options['filters']['field_year_value']['expose']['remember_roles'] = array(
    2 => '2',
    3 => 0,
    1 => 0,
  );
  /* Filter criterion: Content: cittok (field_cittok) */
  $handler->display->display_options['filters']['field_cittok_value']['id'] = 'field_cittok_value';
  $handler->display->display_options['filters']['field_cittok_value']['table'] = 'field_data_field_cittok';
  $handler->display->display_options['filters']['field_cittok_value']['field'] = 'field_cittok_value';
  $handler->display->display_options['filters']['field_cittok_value']['operator'] = '<';
  $handler->display->display_options['filters']['field_cittok_value']['group'] = 2;
  $handler->display->display_options['filters']['field_cittok_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_cittok_value']['expose']['operator_id'] = 'field_cittok_value_op';
  $handler->display->display_options['filters']['field_cittok_value']['expose']['label'] = 'Citations to Kairos';
  $handler->display->display_options['filters']['field_cittok_value']['expose']['description'] = 'Number of Kairos documents cited';
  $handler->display->display_options['filters']['field_cittok_value']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_cittok_value']['expose']['operator'] = 'field_cittok_value_op';
  $handler->display->display_options['filters']['field_cittok_value']['expose']['identifier'] = 'field_cittok_value';
  $handler->display->display_options['filters']['field_cittok_value']['expose']['remember_roles'] = array(
    2 => '2',
    3 => 0,
    1 => 0,
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title_1']['id'] = 'title_1';
  $handler->display->display_options['filters']['title_1']['table'] = 'node';
  $handler->display->display_options['filters']['title_1']['field'] = 'title';
  $handler->display->display_options['filters']['title_1']['operator'] = 'longerthan';
  $handler->display->display_options['filters']['title_1']['value'] = '3';
  $handler->display->display_options['filters']['title_1']['group'] = 2;
  /* Filter criterion: Content: alias (field_alias) */
  $handler->display->display_options['filters']['field_alias_value']['id'] = 'field_alias_value';
  $handler->display->display_options['filters']['field_alias_value']['table'] = 'field_data_field_alias';
  $handler->display->display_options['filters']['field_alias_value']['field'] = 'field_alias_value';
  $handler->display->display_options['filters']['field_alias_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_alias_value']['value'] = 'notdone';
  $handler->display->display_options['filters']['field_alias_value']['group'] = 2;
  $handler->display->display_options['filters']['field_alias_value']['expose']['operator_id'] = 'field_alias_value_op';
  $handler->display->display_options['filters']['field_alias_value']['expose']['label'] = 'alias (field_alias)';
  $handler->display->display_options['filters']['field_alias_value']['expose']['operator'] = 'field_alias_value_op';
  $handler->display->display_options['filters']['field_alias_value']['expose']['identifier'] = 'field_alias_value';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'titles';
  $handler->display->display_options['menu']['title'] = 'Document titles (new)';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['titles'] = array(
    t('Master'),
    t('Titles of Kairos documents'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Title'),
    t('Secondary title'),
    t('Year'),
    t('Citations to Kairos'),
    t('Partno'),
    t('Type'),
    t('Kairos document title'),
    t('Number of Kairos documents cited'),
    t('alias (field_alias)'),
    t('Page'),
  );
  $export['titles'] = $view;

  return $export;
}
