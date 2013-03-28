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
  $handler->display->display_options['title'] = 'Stored Cards';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view own card data';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Commerce Card Data: Referenced customer profile */
  $handler->display->display_options['relationships']['commerce_cardonfile_profile_profile_id']['id'] = 'commerce_cardonfile_profile_profile_id';
  $handler->display->display_options['relationships']['commerce_cardonfile_profile_profile_id']['table'] = 'field_data_commerce_cardonfile_profile';
  $handler->display->display_options['relationships']['commerce_cardonfile_profile_profile_id']['field'] = 'commerce_cardonfile_profile_profile_id';
  /* Field: Commerce Card Data: Card type */
  $handler->display->display_options['fields']['card_type']['id'] = 'card_type';
  $handler->display->display_options['fields']['card_type']['table'] = 'commerce_cardonfile';
  $handler->display->display_options['fields']['card_type']['field'] = 'card_type';
  $handler->display->display_options['fields']['card_type']['label'] = '';
  $handler->display->display_options['fields']['card_type']['alter']['text'] = '<h2>[card_type]</h2>';
  $handler->display->display_options['fields']['card_type']['element_type'] = 'h2';
  $handler->display->display_options['fields']['card_type']['element_label_colon'] = FALSE;
  /* Field: Commerce Card Data: Card number */
  $handler->display->display_options['fields']['card_number']['id'] = 'card_number';
  $handler->display->display_options['fields']['card_number']['table'] = 'commerce_cardonfile';
  $handler->display->display_options['fields']['card_number']['field'] = 'card_number';
  $handler->display->display_options['fields']['card_number']['label'] = 'Ending';
  $handler->display->display_options['fields']['card_number']['element_type'] = 'strong';
  /* Field: Commerce Card Data: Name on the card */
  $handler->display->display_options['fields']['card_name']['id'] = 'card_name';
  $handler->display->display_options['fields']['card_name']['table'] = 'commerce_cardonfile';
  $handler->display->display_options['fields']['card_name']['field'] = 'card_name';
  /* Field: Commerce Card Data: Default card */
  $handler->display->display_options['fields']['instance_default']['id'] = 'instance_default';
  $handler->display->display_options['fields']['instance_default']['table'] = 'commerce_cardonfile';
  $handler->display->display_options['fields']['instance_default']['field'] = 'instance_default';
  $handler->display->display_options['fields']['instance_default']['type'] = 'unicode-yes-no';
  $handler->display->display_options['fields']['instance_default']['not'] = 0;
  /* Field: Commerce Card Data: Card expiration month */
  $handler->display->display_options['fields']['card_exp_month']['id'] = 'card_exp_month';
  $handler->display->display_options['fields']['card_exp_month']['table'] = 'commerce_cardonfile';
  $handler->display->display_options['fields']['card_exp_month']['field'] = 'card_exp_month';
  $handler->display->display_options['fields']['card_exp_month']['exclude'] = TRUE;
  /* Field: Commerce Card Data: Card expiration year */
  $handler->display->display_options['fields']['card_exp_year']['id'] = 'card_exp_year';
  $handler->display->display_options['fields']['card_exp_year']['table'] = 'commerce_cardonfile';
  $handler->display->display_options['fields']['card_exp_year']['field'] = 'card_exp_year';
  $handler->display->display_options['fields']['card_exp_year']['exclude'] = TRUE;
  $handler->display->display_options['fields']['card_exp_year']['separator'] = '';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Expire';
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
  /* Sort criterion: Commerce Card Data: Default card */
  $handler->display->display_options['sorts']['instance_default']['id'] = 'instance_default';
  $handler->display->display_options['sorts']['instance_default']['table'] = 'commerce_cardonfile';
  $handler->display->display_options['sorts']['instance_default']['field'] = 'instance_default';
  /* Contextual filter: Commerce Card Data: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'commerce_cardonfile';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Commerce Card Data: Card data status */
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
  $handler->display->display_options['menu']['title'] = 'Stored Cards';
  $handler->display->display_options['menu']['description'] = 'Edit or delete your stored payment cards.';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;

  $views[$view->name] = $view;


  return $views;
}
