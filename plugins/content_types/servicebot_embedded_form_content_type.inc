<?php

/**
 * @file
 * Content type that displays for the service bot embedded form.
 */

$plugin = [
  'single' => TRUE,
  'title' => t('Servicebot embedded form'),
  'description' => t(
    'Displays the servicebot embedded form.'
  ),
  'category' => t('Servicebot'),
  'admin info' => 'servicebot_embedded_form_content_type_admin_info',
  'render callback' => 'servicebot_embedded_form_content_type_render',
  'edit form' => 'servicebot_embedded_form_content_type_edit_form',
  'defaults' => [
    'hideCancelDropdown' => FALSE,
    'disableCoupon' => FALSE,
    'hideChangePlan' => FALSE,
    'hideUpdateCard' => FALSE,
    'forceCard' => FALSE,
    'cancel_now' => FALSE,
    'messageOnCancel' => '',
    'metadata' => '',
    'object' => '',
    'card.hideName' => FALSE,
    'card.hideAddress' => FALSE,
    'card.hideCountryPostal' => FALSE,
  ],
];

/**
 * Ctools pane config form.
 */
function servicebot_embedded_form_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['options'] = [
    '#type' => 'fieldset',
    '#title' => t('Servicebot Options'),
    '#description' => t('Follow instructions on servicebot options !here.',
      ['!here' => l('here', 'https://docs.servicebot.io/subscription-portal/advance-configuration/configure-portal#options')]),
  ];

  $form['options']['hideCancelDropdown'] = [
    '#type' => 'checkbox',
    '#title' => 'hideCancelDropdown',
    '#description' => t('Set to true to disable users from being able to cancel their subscription on their own.'),
    '#default_value' => !empty($conf['hideCancelDropdown']) ? $conf['hideCancelDropdown'] : FALSE,
  ];

  $form['options']['disableCoupon'] = [
    '#type' => 'checkbox',
    '#title' => 'disableCoupon',
    '#description' => t('Set to true to hide the coupon section from users on signup and on the subscription management portal.'),
    '#default_value' => !empty($conf['disableCoupon']) ? $conf['disableCoupon'] : FALSE,
  ];

  $form['options']['hideChangePlan'] = [
    '#type' => 'checkbox',
    '#title' => 'hideChangePlan',
    '#description' => t('Set to true to disable users from being able to change their plan (upgrade/downgrade).'),
    '#default_value' => !empty($conf['hideChangePlan']) ? $conf['hideChangePlan'] : FALSE,
  ];

  $form['options']['hideUpdateCard'] = [
    '#type' => 'checkbox',
    '#title' => 'hideUpdateCard',
    '#description' => t('Set to true to disable users from being able to update their Credit Card information.'),
    '#default_value' => !empty($conf['hideUpdateCard']) ? $conf['hideUpdateCard'] : FALSE,
  ];

  $form['options']['forceCard'] = [
    '#type' => 'checkbox',
    '#title' => 'forceCard',
    '#description' => t('Set to true to force users to enter in their Credit Card information during signup process. By default the embed will not ask for payment information if they are on a free tier or there is a free trial.'),
    '#default_value' => !empty($conf['forceCard']) ? $conf['forceCard'] : FALSE,
  ];

  $form['options']['cancel_now'] = [
    '#type' => 'checkbox',
    '#title' => 'cancel_now',
    '#description' => t('Set to true to force cancellations to go through immediately. By default Servicebot will cancel a subscription at the end of the billing cycle.'),
    '#default_value' => !empty($conf['cancel_now']) ? $conf['cancel_now'] : FALSE,
  ];

  // @TODO Implement this option.
  // disableTiers

  $form['options']['messageOnCancel'] = [
    '#type' => 'text',
    '#title' => 'messageOnCancel',
    '#description' => t('A message to override the default cancellation message. When a user selects to cancel their plan, this is the message that appears in the pop-up'),
    '#default_value' => !empty($conf['messageOnCancel']) ? $conf['messageOnCancel'] : FALSE,
  ];

  $form['options']['metadata'] = [
    '#type' => 'textarea',
    '#title' => 'metadata',
    '#description' => t("An object of key-value pairs. They will be added to the metadata of the Customer and Subscription in Stripe when they are created using the portal.
Eg: {key1: 'value1', key2:'value2'}"),
    '#default_value' => !empty($conf['metadata']) ? $conf['metadata'] : FALSE,
  ];

  $form['options']['object'] = [
    '#type' => 'textarea',
    '#title' => 'object',
    '#description' => t("Use to set the quantity of a subscription during creation. Can get an integer or an object of key-value pairs. The quantity will apply to products with the unti_label defined. If an integer is passed, it will apply the quantity to all products on the tier, if an object is passed with the unit_labels as keys, it will assign that quantity to the respective unit_label.
Eg: 5
Eg: {product_unit_label1 : 10, unit_label2: 20}"),
    '#default_value' => !empty($conf['object']) ? $conf['object'] : FALSE,
  ];

  $form['options']['card.hideName'] = [
    '#type' => 'checkbox',
    '#title' => 'card.hideName',
    '#description' => t('Set to true to hide the name field on the Credit Card form.'),
    '#default_value' => !empty($conf['card.hideName']) ? $conf['card.hideName'] : FALSE,
  ];

  $form['options']['card.hideAddress'] = [
    '#type' => 'checkbox',
    '#title' => 'card.hideAddress',
    '#description' => t('Set to true to hide the address field on the Credit Card form.'),
    '#default_value' => !empty($conf['card.hideAddress']) ? $conf['card.hideAddress'] : FALSE,
  ];

  $form['options']['card.hideCountryPostal'] = [
    '#type' => 'checkbox',
    '#title' => 'card.hideCountryPostal',
    '#description' => t('Set to true to hide the Country and Postal Code fields on the Credit Card form'),
    '#default_value' => !empty($conf['card.hideCountryPostal']) ? $conf['card.hideCountryPostal'] : FALSE,
  ];

  return $form;
}

/**
 * Settings form submit handler.
 */
function servicebot_embedded_form_content_type_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Admin block info.
 */
function servicebot_embedded_form_content_type_admin_info($subtype, $conf, $context) {
  $block = new Stdclass;
  $block->title = 'Servicebot';
  $block->content = t('Displays the servicebot embedded form');
  return $block;
}


/**
 * Run-time rendering of the body of the block.
 *
 * @param $subtype
 * @param $conf
 *   Configuration as done at admin time
 * @param $args
 * @param $context
 *   Context - in this case we don't have any
 *
 * @return
 *   Rendered servicebot embedded form.
 */
function servicebot_embedded_form_content_type_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->title = '';

  global $user;
  $secret_key = variable_get('servicebot_secret_key', '');

  $email_hash = hash_hmac(
    'sha256',
    $user->mail,
    $secret_key
  );

  $block->content = [
    '#markup' => theme('servicebot_subscription_embed', [
      'user_mail' => $user->mail,
      'user_hmac' => $email_hash,
      'servicebot_id' => variable_get('servicebot_id', ''),
    ])
  ];

  return $block;
}
