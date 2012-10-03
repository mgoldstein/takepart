(function($) {
  Drupal.behaviors.pledges = {
    attach: function(context) {
      
      // TODO: MOVE THIS TO PETITION.JS WHENEVER IT'S MADE
      $('.node-petition-action').once('petition-js', function(){
        $('.field-name-field-petition-sponsor', '.node-petition-action').once('add-commas', function(){
          $(this).find('.field-item').not(':last').append(', ');
        }); // add commas to sponsors
      });
    
      // $(document).ready and after every ajax call
      var container = $('.node-pledge-action');
      container.once('pledges-js', _init);
      
      // $(document).ready only
      function _init(){
        // variables
        var container = $(this);
        var wycdLongContainter = $('.field-name-field-pledge-action-long', container).addClass('inactive');
        var wycdShortContainer = $('.field-name-field-pledge-action-short', container).addClass('active');
        var wycdMoreLabel = 'Read more.';
        var wycdLessLabel = 'Read less.';
                      
        // on load
        var wycdLink = $('.wycdLink', container);
        console.log(container);
        container.once('add-wycd-link', function(){
          wycdLink = $('<a href="javascript:void(0)">' + wycdMoreLabel + '</a>').addClass('wycdLink').insertAfter(wycdShortContainer);
        });// add wycdLink
        
        $('.field-name-field-petition-sponsor', container).once('add-commas', function(){
          $(this).find('.field-item').not(':last').append(', ');
        }); // add commas to sponsors
        
        // bind actions
        container.bind('click', _click);
        
        // action handlers
        function _click(event){
          var target = $(event.target);
          
          // show more / show less link click
          if (target.is('.wycdLink') || target.parents(".wycdLink").length) {
            target = target.is(".wycdLink") ? target : target.parents(".wycdLink");
            wycdShortContainer.toggleClass('inactive').toggleClass('active');
            wycdLongContainter.toggleClass('inactive').toggleClass('active');
            if (wycdShortContainer.hasClass('active')){
              wycdLink.text(wycdMoreLabel);
            } else {
              wycdLink.text(wycdLessLabel);
            }
          }
        };
      }
    }
  };
})(jQuery);
