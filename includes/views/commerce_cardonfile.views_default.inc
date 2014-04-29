<?php

/**
 * @file
 * Views for the default Commerce Card on File.
 */

/**
 * Implements hook_views_default_views().
 */
function commerce_cardonfile_views_default_views() {
  $views = array();

  // Stored cards: User
  $view = new view();
  $view->name = 'commerce_card_on_file_user_cards';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'commerce_cardonfile';
  $view->human_name = 'Commerce Card on File: User Cards';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Stored cards';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view own card data';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'card_type' => 'card_type',
    'card_number' => 'card_number',
    'card_name' => 'card_name',
    'instance_default' => 'instance_default',
    'card_exp_month' => 'card_exp_month',
    'card_exp_year' => 'card_exp_year',
    'nothing' => 'nothing',
    'commerce_cardonfile_profile' => 'commerce_cardonfile_profile',
    'edit_card' => 'edit_card',
    'delete_card' => 'edit_card',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'card_type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'card_number' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'card_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'instance_default' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'card_exp_month' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'card_exp_year' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'commerce_cardonfile_profile' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_card' => array(
      'align' => '',
      'separator' => ' | ',
      'empty_column' => 0,
    ),
    'delete_card' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Commerce Card Data: Referenced customer profile */
  $handler->display->display_options['relationships']['commerce_cardonfile_profile_profile_id']['id'] = 'commerce_cardonfile_profile_profile_id';
  $handler->display->display_options['relationships']['commerce_cardonfile_profile_profile_id']['table'] = 'field_data_commerce_cardonfile_profile';
  $handler->display->display_options['relationships']['commerce_cardonfile_profile_profile_id']['field'] = 'commerce_cardonfile_profile_profile_id';
  /* Field: Commerce Card on File: Card type */
  $handler->display->display_options['fields']['card_type']['id'] = 'card_type';
  $handler->display->display_options['fields']['card_type']['table'] = 'commerce_cardonfile';
  $handler->display->display_options['fields']['card_type']['field'] = 'card_type';
  $handler->display->display_options['fields']['card_type']['label'] = '';
  $handler->display->display_options['fields']['card_type']['alter']['text'] = '<h2>[card_type]</h2>';
  $handler->display->display_options['fields']['card_type']['element_type'] = 'h2';
  $handler->display->display_options['fields']['card_type']['element_label_colon'] = FALSE;
  /* Field: Commerce Card on File: Card number */
  $handler->display->display_options['fields']['card_number']['id'] = 'card_number';
  $handler->display->display_options['fields']['card_number']['table'] = 'commerce_cardonfile';
  $handler->display->display_options['fields']['card_number']['field'] = 'card_number';
  $handler->display->display_options['fields']['card_number']['label'] = 'Ending';
  $handler->display->display_options['fields']['card_number']['element_type'] = 'strong';
  /* Field: Commerce Card on File: Name on the card */
  $handler->display->display_options['fields']['card_name']['id'] = 'card_name';
  $handler->display->display_options['fields']['card_name']['table'] = 'commerce_cardonfile';
  $handler->display->display_options['fields']['card_name']['field'] = 'card_name';
  /* Field: Commerce Card on File: Default card */
  $handler->display->display_options['fields']['instance_default']['id'] = 'instance_default';
  $handler->display->display_options['fields']['instance_default']['table'] = 'commerce_cardonfile';
  $handler->display->display_options['fields']['instance_default']['field'] = 'instance_default';
  $handler->display->display_options['fields']['instance_default']['type'] = 'unicode-yes-no';
  $handler->display->display_options['fields']['instance_default']['not'] = 0;
  /* Field: Commerce Card on File: Card expiration month */
  $handler->display->display_options['fields']['card_exp_month']['id'] = 'card_exp_month';
  $handler->display->display_options['fields']['card_exp_month']['table'] = 'commerce_cardonfile';
  $handler->display->display_options['fields']['card_exp_month']['field'] = 'card_exp_month';
  $handler->display->display_options['fields']['card_exp_month']['exclude'] = TRUE;
  /* Field: Commerce Card on File: Card expiration year */
  $handler->display->display_options['fields']['card_exp_year']['id'] = 'card_exp_year';
  $handler->display->display_options['fields']['card_exp_year']['table'] = 'commerce_cardonfile';
  $handler->display->display_options['fields']['card_exp_year']['field'] = 'card_exp_year';
  $handler->display->display_options['fields']['card_exp_year']['exclude'] = TRUE;
  $handler->display->display_options['fields']['card_exp_year']['separator'] = '';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Expires';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[card_exp_month] / [card_exp_year]';
  /* Field: Commerce Card Data: Billing Profile */
  $handler->display->display_options['fields']['commerce_cardonfile_profile']['id'] = 'commerce_cardonfile_profile';
  $handler->display->display_options['fields']['commerce_cardonfile_profile']['table'] = 'field_data_commerce_cardonfile_profile';
  $handler->display->display_options['fields']['commerce_cardonfile_profile']['field'] = 'commerce_cardonfile_profile';
  $handler->display->display_options['fields']['commerce_cardonfile_profile']['label'] = 'Address';
  $handler->display->display_options['fields']['commerce_cardonfile_profile']['element_type'] = '0';
  $handler->display->display_options['fields']['commerce_cardonfile_profile']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['commerce_cardonfile_profile']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['commerce_cardonfile_profile']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['commerce_cardonfile_profile']['field_api_classes'] = TRUE;
  /* Field: Commerce Card on File: Edit link */
  $handler->display->display_options['fields']['edit_card']['id'] = 'edit_card';
  $handler->display->display_options['fields']['edit_card']['table'] = 'commerce_cardonfile';
  $handler->display->display_options['fields']['edit_card']['field'] = 'edit_card';
  $handler->display->display_options['fields']['edit_card']['label'] = 'Actions';
  $handler->display->display_options['fields']['edit_card']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_card']['text'] = 'Edit';
  /* Field: Commerce Card on File: Delete link */
  $handler->display->display_options['fields']['delete_card']['id'] = 'delete_card';
  $handler->display->display_options['fields']['delete_card']['table'] = 'commerce_cardonfile';
  $handler->display->display_options['fields']['delete_card']['field'] = 'delete_card';
  $handler->display->display_options['fields']['delete_card']['label'] = '';
  $handler->display->display_options['fields']['delete_card']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['delete_card']['text'] = 'Delete';
  /* Sort criterion: Commerce Card on File: Default card */
  $handler->display->display_options['sorts']['instance_default']['id'] = 'instance_default';
  $handler->display->display_options['sorts']['instance_default']['table'] = 'commerce_cardonfile';
  $handler->display->display_options['sorts']['instance_default']['field'] = 'instance_default';
  /* Contextual filter: Commerce Card on File: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'commerce_cardonfile';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Commerce Card on File: Card data status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'commerce_cardonfile';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'user/%/cards';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Stored cards';
  $handler->display->display_options['menu']['description'] = 'Manage your stored card data.';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $translatables['commerce_card_on_file_user_cards'] = array(
    t('Master'),
    t('Stored cards'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Customer profile'),
    t('<h2>[card_type]</h2>'),
    t('Ending'),
    t('Name on the card'),
    t('Default card'),
    t('Card expiration month'),
    t('.'),
    t(','),
    t('Card expiration year'),
    t('Expires'),
    t('[card_exp_month] / [card_exp_year]'),
    t('Address'),
    t('Actions'),
    t('Edit'),
    t('Delete'),
    t('All'),
    t('Page'),
  );

  $views[$view->name] = $view;

  return $views;
}
