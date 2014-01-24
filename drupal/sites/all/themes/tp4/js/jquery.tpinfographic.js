// This library uses $.tpmodal and takepart.analytics
(function($, window, document, undefined) {

    /**
     * Automatically embed TP Infographic embed code 
     */
    $.fn.tpInfographic = function() {
        return this.each(function() {
            // store a reference to the current object
            var $this = $(this);
            var infographicAlt = $this.find('img').attr('alt');

            // Create a wrapping div for the embed code and toggle link
            var $container = $('<div class="tpinfographic_embed_container" />').insertAfter(this);

            // Create a <textarea> with the embed code
            var embedCode = $this.html().replace(/^\s+|\s+$/g, '').replace(/\n/g, '').replace(/\s+/g, ' ') + '<br />Via: <a href="http://www.takepart.com">TakePart.com</a>';
            var $embed = $('<textarea class="tpinfographic_embed_textarea" />')
                .attr({readonly: 'readonly', cols: 75, rows: 7})
                .val(embedCode)
                .wrap('<p class="tpinfographic_embed_textarea" />')
                .parent()
                    .on('focus', 'textarea', function(e) {
                        e.currentTarget.select();
                    })
                    .on('mouseup', 'textarea', function(e) {
                        e.preventDefault();
                    })
                    .hide()
                    .appendTo($container)
            ;

            // create a toggle link for the embed code
            $('<a href="#">Embed This Infographic on Your Site</a>')
                .wrap('<p class="tpinfographic_embed_link" />')
                .parent()
                    .on('click', 'a', function(e) {
                        e.preventDefault();
                        if (!$embed.is(':visible')) {
                            takepart.analytics.track('tpinfographic_embed_show', {name: infographicAlt});
                            $embed.slideDown();
                        }
                    })
                    .prependTo($container);
            ;

            $this.on('click', 'a', function(e){
                e.preventDefault();
                takepart.analytics.track('tpinfographic_show', {name: infographicAlt});
                $.tpmodal.show({id: 'tpinfographic_modal_', url: this.href, hideOnModalClick: true});
            });

        });
    };
})(jQuery, this, this.document);
