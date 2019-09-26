/**
 * @file display_editor.js
 *
 * Contains the javascript for the Panels display editor.
 */

(function ($) {
    Drupal.behaviors.servicebot = {
        attach: function (context, settings) {
            window.servicebotSettings = {
                servicebot_id: Drupal.settings.servicebot.servicebot_id,
                options: Drupal.settings.servicebot.servicebot_options,
                email: Drupal.settings.servicebot.user_mail,
                email_hash: Drupal.settings.servicebot.user_hmac,
                service: Drupal.settings.servicebot.servicebot_service,
                tier: Drupal.settings.servicebot.servicebot_tier,
                interval: Drupal.settings.servicebot.servicebot_interval
            };
            (function () {
                var s = document.createElement('script');
                s.src = 'https://js.servicebot.io/embeds/servicebot-billing-settings-embed.js';
                s.async = true;
                s.type = 'text/javascript';
                var x = document.getElementsByTagName('script')[0];
                x.parentNode.insertBefore(s, x);
            })();
        }
    };
})(jQuery);