(function($) {

  // detect localstorage
  var hasStorage = (function() {
    try {
      localStorage.setItem('foo', 'test');
      localStorage.removeItem('test');
      return true;
    } catch (e) {
      return false;
    }
  })();

  var nameCache = (hasStorage && JSON.parse(localStorage.getItem('sysSchoolCache'))) || {};

  $.extend($.fn, {
    schoolBrowser: function() {
      // this plugin only works on form elements
      return this.filter('form').each(function() {
        var $this = $(this);
        var $schoolState = $this.find('#school_state');
        var $schoolName = $this.find('#school_name');
        var $schoolCity = $this.find('#school_city');
        var $schoolId = $this.find('#school_id');

        var $schoolNameMessage = $('<p class="character-count" />')
          .addClass('character-count-school-name')
          .insertAfter($schoolName)
        ;

        if ($.fn.customSelect) {
          $schoolState.not('.hasCustomSelect').customSelect();
        }

        $schoolState.on('change', function() {
            $schoolName.attr('disabled', $schoolState.val() === "");
        });

        $schoolName.on('change', function() {
          if (!$schoolName.data('autocompleteOpen')) {
            $schoolId.val('0');
            $schoolCity.val('');
          }
        }).on('blur', function() {
          $schoolName.removeClass('in-progress');
        });

        var resetSchoolNameMessage = function() {
            $schoolNameMessage.removeClass('count-warning').html('');
        };

        var updateSchoolFields = function(e, ui) {
            $schoolName.val(ui.item.label.split(' (')[0]);
            $schoolId.val(ui.item.value.school_id);
            $schoolCity.val(ui.item.value.school_city);
            resetSchoolNameMessage();
            return false; // prevent default behaivor
        };

        $schoolName.autocomplete({
            minLength: 4,
            select: updateSchoolFields,
            focus: updateSchoolFields,
            blur: updateSchoolFields,
            search: function() {
                $schoolName.addClass('in-progress');
                resetSchoolNameMessage();
            },
            open: function() {
                $schoolName.removeClass('in-progress').data('autocompleteOpen', true);
                resetSchoolNameMessage();
            },
            close: function() {
                resetSchoolNameMessage();
                setTimeout(function() {
                    $schoolName.data('autocompleteOpen', false);
                }, 1000)
            },
            source: function(request, response) {

              var hash = encodeURIComponent('&state=' + $schoolState.val() + '&q=' + encodeURIComponent(request.term));
              if (hash in nameCache) {
                response(nameCache[hash]);
                return;
              }

              $.ajax({
                url: '/proxy?request=' + encodeURIComponent('http://api.greatschools.org/search/schools/?key=zzlcyx4aijxe1nmnagoziqxx') + hash,
                error: function() {
                    var errorMessage = [
                        "We can't find &quot;" + request.term.htmlEntities() + "&quot;.",
                        "For best results, type a single, complete word and choose from the list."
                    ];
                    $schoolName.removeClass('in-progress');
                    $schoolNameMessage
                            .addClass('count-warning')
                            .html(errorMessage.join('<br/>'));
                },
                success: function(data, textStatus, jqXHR) {
                    var schools = [];
                    $(data).find('school').each(function() {
                        var $this = $(this);
                        schools.push({
                            label: $this.find('name').text() + ' (' + $this.find('city').text() + ', ' + $this.find('state').text() + ')',
                            value: {
                                school_id: $this.find('gsId').text(),
                                school_city: $this.find('city').text(),
                                school_state: $this.find('state').text()
                            }
                        });
                    });
                    nameCache[hash] = schools;
                    hasStorage && localStorage.setItem('sysSchoolCache', JSON.stringify(nameCache));
                    response(schools);
                }
              });
            }
        });

      });
    }
  });

})(jQuery);