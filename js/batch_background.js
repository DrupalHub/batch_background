
(function ($) {

  Drupal.behaviors.batchBackground = {
    attach: function (context, settings) {
      if (settings.batch_background == "") {
        return;
      }

      var callbacks = settings.batch_background;

      $.each(callbacks, function(index, value) {
        $.get(settings.base_url + '?q=batch_background/process/' + value[0] + '/' + value[1]);
      });

    }
  };

})(jQuery);
