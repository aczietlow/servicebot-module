<?php

/**
 * @file
 * Servicebot admin config.
 */

/**
 * Servicebot admin settings form.
 */
function servicebot_settings_form($form, &$form_state) {
  $form['credentials'] = [
    '#type' => 'fieldset',
    '#title' => t('Servicebot credentials'),
    '#description' => t('Follow the instructions to set up your Servicebot credentials !here.',
      ['!here' => l('here', 'https://docs.servicebot.io/subscription-portal/get-started')]),
  ];

  $form['credentials']['servicebot_secret_key'] = [
    '#type' => 'textfield',
    '#title' => t('Secret Key'),
    '#default_value' => variable_get('servicebot_secret_key', ''),
    '#required' => TRUE,
    '#description' => t('Servicebot unique ID associated with your account. It can be found on the Dashboard->Subscription Portal. Note: This ID is different for Live & Test mode.'),
  ];

  $form['credentials']['servicebot_id'] = [
    '#type' => 'textfield',
    '#title' => t('ID'),
    '#default_value' => variable_get('servicebot_id', ''),
    '#required' => TRUE,
    '#description' => t('Servicebot ID'),
  ];

  $form['settings'] = [
    '#type' => 'fieldset',
    '#title' => t('Servicebot Settings'),
    '#description' => t('Follow instructions on servicebot settings !here.',
      ['!here' => l('here', 'https://docs.servicebot.io/subscription-portal/advance-configuration/configure-portal')]),
  ];

  $form['settings']['servicebot_service'] = [
    '#type' => 'textfield',
    '#title' => t('service'),
    '#default_value' => variable_get('servicebot_service', ''),
    '#description' => t('The service name configured in Stripe (metadata sb_service). This is required to use the Plan Picker functionality and to use the portal for signup.'),
  ];

  $form['settings']['servicebot_tier'] = [
    '#type' => 'textfield',
    '#title' => t('tier'),
    '#default_value' => variable_get('servicebot_tier', ''),
    '#description' => t('The tier name configured in Stripe (metadata sb_tier). This is required in the signup process if you want to automatically register a user for a specific tier and interval.'),
  ];

  $form['settings']['servicebot_interval'] = [
    '#type' => 'textfield',
    '#title' => t('interval'),
    '#default_value' => variable_get('servicebot_interval', ''),
    '#description' => t('The interval value of the plan (day, month, year). This is required in the signup process if you want to automatically register a user for a specific tier and interval. Note: Not required if there is only one interval on that tier.'),
  ];

  $form['options'] = [
    '#type' => 'fieldset',
    '#title' => t('Servicebot Options'),
    '#description' => t('Follow instructions on servicebot options !here.',
      ['!here' => l('here', 'https://docs.servicebot.io/subscription-portal/advance-configuration/configure-portal#options')]),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  ];

  $form['options']['servicebot_global_hideCancelDropdown'] = [
    '#type' => 'checkbox',
    '#title' => 'hideCancelDropdown',
    '#description' => t('Set to true to disable users from being able to cancel their subscription on their own.'),
    '#default_value' => variable_get('servicebot_global_hideCancelDropdown', FALSE),
  ];

  $form['options']['servicebot_global_hideCoupon'] = [
    '#type' => 'checkbox',
    '#title' => 'hideCoupon',
    '#description' => t('Set to true to hide the coupon section from users.'),
    '#default_value' => variable_get('servicebot_global_hideCoupon', FALSE),
  ];

  $form['options']['servicebot_global_hideChangePlan'] = [
    '#type' => 'checkbox',
    '#title' => 'hideChangePlan',
    '#description' => t('Set to true to disable users from being able to change their plan (upgrade/downgrade).'),
    '#default_value' => variable_get('servicebot_global_hideChangePlan', FALSE),
  ];

  $form['options']['servicebot_global_hideUpdateCard'] = [
    '#type' => 'checkbox',
    '#title' => 'hideUpdateCard',
    '#description' => t('Set to true to disable users from being able to update their Credit Card information.'),
    '#default_value' => variable_get('servicebot_global_hideUpdateCard', FALSE),
  ];

  $form['options']['servicebot_global_forceCard'] = [
    '#type' => 'checkbox',
    '#title' => 'forceCard',
    '#description' => t('Set to true to force users to enter in their Credit Card information during signup process. By default the embed will not ask for payment information if they are on a free tier or there is a free trial.'),
    '#default_value' => variable_get('servicebot_global_forceCard', FALSE),
  ];

  $form['options']['servicebot_global_cancel_now'] = [
    '#type' => 'checkbox',
    '#title' => 'cancel_now',
    '#description' => t('Set to true to force cancellations to go through immediately. By default Servicebot will cancel a subscription at the end of the billing cycle.'),
    '#default_value' => variable_get('servicebot_global_cancel_now', FALSE),
  ];

  // @TODO Implement this option.
  // disableTiers

  $form['options']['servicebot_global_messageOnCancel'] = [
    '#type' => 'text',
    '#title' => 'messageOnCancel',
    '#description' => t('A message to override the default cancellation message. When a user selects to cancel their plan, this is the message that appears in the pop-up'),
    '#default_value' => variable_get('servicebot_global_messageOnCancel', FALSE),
  ];

  $form['options']['servicebot_global_metadata'] = [
    '#type' => 'textarea',
    '#title' => 'metadata',
    '#description' => t("An object of key-value pairs. They will be added to the metadata of the Customer and Subscription in Stripe when they are created using the portal.
Eg: {key1: 'value1', key2:'value2'}"),
    '#default_value' => variable_get('servicebot_global_metadata', ''),
  ];

  $form['options']['servicebot_global_object'] = [
    '#type' => 'textarea',
    '#title' => 'object',
    '#description' => t("Use to set the quantity of a subscription during creation. Can get an integer or an object of key-value pairs. The quantity will apply to products with the unti_label defined. If an integer is passed, it will apply the quantity to all products on the tier, if an object is passed with the unit_labels as keys, it will assign that quantity to the respective unit_label.
Eg: 5
Eg: {product_unit_label1 : 10, unit_label2: 20}"),
    '#default_value' => variable_get('servicebot_global_object', ''),
  ];

  $form['options']['servicebot_global_card.hideName'] = [
    '#type' => 'checkbox',
    '#title' => 'card.hideName',
    '#description' => t('Set to true to hide the name field on the Credit Card form.'),
    '#default_value' => variable_get('servicebot_global_card.hideName', FALSE),
  ];

  $form['options']['servicebot_global_card.hideAddress'] = [
    '#type' => 'checkbox',
    '#title' => 'card.hideAddress',
    '#description' => t('Set to true to hide the address field on the Credit Card form.'),
    '#default_value' => variable_get('servicebot_global_card.hideAddress', FALSE),
  ];

  $form['options']['servicebot_global_card.hideCountryPostal'] = [
    '#type' => 'checkbox',
    '#title' => 'card.hideCountryPostal',
    '#description' => t('Set to true to hide the Country and Postal Code fields on the Credit Card form'),
    '#default_value' => variable_get('servicebot_global_card.hideCountryPostal', FALSE),
  ];

  return system_settings_form($form);
}
