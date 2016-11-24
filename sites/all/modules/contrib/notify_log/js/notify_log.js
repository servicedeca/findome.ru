/**
 * @file
 * Display new log entries via JS.
 */

(function ($) {

  /**
   * Notify users about new log entries.
   */
  Drupal.behaviors.notifyLog = {
    attach: function (context, settings) {
      if (typeof(Drupal.settings.notifyLog) != 'undefined') {
        $.each(Drupal.settings.notifyLog, function(key, value) {
          $.growl(value);
        });
        Drupal.settings.notifyLog = undefined;
      }
    }
  };

})(jQuery);
