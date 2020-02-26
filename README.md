# Servicebot module

This module provides Drupal integration with servicebot. It requires a servicebot account to work correctly.

## Configuration

Once enabled navigate to `admin/config/services/servicebot`. Enter the service bot id and secret key from the desired service bot account.

In order to use the subscription sign up and billing features you will need to list the name of the "service" configured within Stripe. This value comes from your stripe account.

### Advance Servicebot options

Navigate to `admin/config/services/servicebot` to customize the service bot experience, but toggling options, and including additional metadata in the servicebot requests.

### Webhooks

Navigate to `admin/config/services/servicebot` to enable the webhooks url. The default webhooks url is `servicebot/webhooks`. This should be configured as the webhooks endpoint within Stripe. The following events should can be configured with the Drupal servicebot webhooks URL to work:

* customer.subscription.created
* customer.subscription.deleted
* customer.subscription.updated
* customer.source.created
* customer.source.expiring
* customer.source.updated
* customer.subscription.trial_will_end
* invoice.payment_failed

Note that the webhooks do nothing once enabled, other than expose the stripe events via Drupal hooks to the developer. This is inorder to further extend the servicebot integration. These hooks are documented within servicebot.api.php

## Usage

Out of the box servicebot ships with a billing portal available at `/billing` this can be configured through the UI in the settings page. Additionally there is a block and ctools content type that can be used as a panels pane to be placed within a Drupal site.

MAINTAINERS
-----------

Current maintainers:
 * Chris Zietlow (aczietlow) - https://www.drupal.org/u/aczietlow

This project has been sponsored by:
 * Mindgrub
   We create digital experiences that matter. Visit https://www.mindgrub.com/
 