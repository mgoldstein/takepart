(function ($) {
    $.fn.extend({
        takepartStyle: function (options) {
            if (!$.browser.msie || ($.browser.msie && $.browser.version > 6)) {
                return this.each(function () {
                    var currentSelected = $(this).find(':selected');
                    $(this).after('<span class="customStyleSelectBox"><span class="customStyleSelectBoxInner">' + currentSelected.text() + '</span></span>').css({
                        position: 'absolute',
                        opacity: 0,
                        fontSize: $(this).next().css('font-size')
                    });
                    var selectBoxSpan = $(this).next();
                    var selectBoxWidth = parseInt($(this).width()) - parseInt(selectBoxSpan.css('padding-left')) - parseInt(selectBoxSpan.css('padding-right')) + 10;
                    var selectBoxSpanInner = selectBoxSpan.find(':first-child');
                    selectBoxSpan.css({
                        display: 'inline-block'
                    });
                    selectBoxSpanInner.css({
                        width: selectBoxWidth,
                        display: 'inline-block'
                    });
                    var selectBoxHeight = parseInt(selectBoxSpan.height()) + parseInt(selectBoxSpan.css('padding-top')) + parseInt(selectBoxSpan.css('padding-bottom')) + 3;
                    $(this).width(($(this).width()) + 13);
                    $(this).height(selectBoxHeight).change(function () {
                        selectBoxSpanInner.text($(this).find(':selected').text()).parent().addClass('changed');
                    });

                });
            }
        }
    });
})(jQuery);