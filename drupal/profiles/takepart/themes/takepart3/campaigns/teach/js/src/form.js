(function($, TEACH, window, document, undefined) {

    // convenience values for COPPA compliance
    var coppaCookieName = "pm_sys_user_birthdate",
            coppaCookieExpires = 1, // days to keep the cookie
            msDay = 24 * 60 * 60 * 1000, // one day in milliseconds
            ageRequirement = Date.now() - 13 * 365 * msDay; // 13 years in milliseconds


    // show coppa error message and delete form from page
    var showCoppaErrorMessage = function() {
        $('#sys-form-content').slideUp();
        $('#sys-coppa-content').removeClass('initially-hidden');
        $('html, body').animate({
            scrollTop: $('.menu-wrapper').offset().top - 25
        });
    };

    var sysFormSubmit = function(form) {
        var $form = $(form);
        var formData = parseFormData($form);
        var userBirthdate = new Date(formData.user_year, formData.user_month, formData.user_day);

        var $submit = $form.find('input[type=submit]').addClass('in-progress');

        if (userBirthdate.getTime() > ageRequirement) {

            // set coppa cookie
            var expires = new Date();
            expires.setTime(expires.getTime() + coppaCookieExpires * msDay);
            document.cookie = escape(coppaCookieName) + "=" + userBirthdate.getTime() + "; expires=" + expires.toGMTString() + '; path=/';

            showCoppaErrorMessage();

            return false;
        }

        // we've passed the age check. Lets have a beer.

        var json = {
            "format": "json",
            "action_id": TEACH.TAP.action_id,
            "opt_ins": {},
            "user_action": {
                "partner_code": TEACH.TAP.partner_code,
                "email": formData.email,
                "last_name": formData.first_name,
                "first_name": formData.last_name,
		"image_link": formData.user_image_link || '',
		"image_uid": formData.user_image_id || '',
                // boilerplate
                "zip": "90210",
                "state": "CA",
                "city": "Beverly Hills",
                "address": "331 Foothill Rd."
            },
            "story": {
                "year": formData.story_year,
                "preview": "",
                "title": formData.story_title,
                "body": formData.story_body
            },
            "teacher": {
                "first_name": formData.teacher_first_name,
                "last_name": formData.teacher_last_name,
		"image_link": formData.teacher_image_link || '',
		"image_uid": formData.teacher_image_id || ''
            },
            "school": {
                "name": formData.school_name,
                "city": formData.school_city,
                "state": formData.school_state,
                "external_id": formData.school_id
            }
        };

        if (formData.email_subscribe == true) {
            json.opt_ins.teach_stories = "true";
        }

        $.ajax({
            type: 'POST',
            url: TEACH.TAP.postURL,
            data: JSON.stringify(json),
            contentType: 'application/json',
            dataType: 'json',
            success: function(data, textStatus, jqXHR) {
                $('#sys-form-content').slideUp();
                $('#sys-thanks-content').removeClass('initially-hidden');
		$('html, body').animate({
		    scrollTop: $('.menu-wrapper').offset().top - 25
		});
                /* Analytics */
                takepart.analytics.track('teach_story_entry');
            },
            error: function(jqXHR, textStatus, errorThrown) {
                $submit.removeClass('in-progress');
                alert('There was an error submitting your story.');
            }
        });

    };

    var parseFormData = function($form) {
        var formData = {};
        $form.find("input, textarea, select").not('[type="checkbox"], [type="file"]').each(function() {
            // @see String.prototype.htmlEntities
            formData[this.id] = $(this).val().trim().replace(/\n+/g, ' ').htmlEntities();
        });

        formData.story_title = formData.teacher_first_name + ' ' + formData.teacher_last_name;

        // get more useful checkbox values
        formData.email_subscribe = $form.find('#email_subscribe').is(':checked');
        formData.terms_agree = $form.find('#terms_agree').is(':checked');

        return formData;
    };

    // not using Drupal.behaviors because this JS has nothing to do with drupal
    $(document).ready(function() {
        // coppa check
        var birthDate = null;
        $.each(document.cookie.split(";"), function() {
            if (this.trim().indexOf(escape(coppaCookieName)) === 0) {
                birthDate = unescape(this.trim().substring(escape(coppaCookieName).length + 1, this.length));
            }
        });

        if (birthDate && (birthDate > ageRequirement)) {
            showCoppaErrorMessage();
            return false;
        }

        // we've passed the age test. have a beer.
        var $form = $('#sys-form');

        // populate character count divs from maxlength properties
        $form.find('input[maxlength], textarea[maxlength]').each(function() {
            var $this = $(this),
                    maxlength = $this.attr('maxlength');

            // build up character count elements:
            // <p class="character-count character-count-story-body"><span></span> Characters Left</p>
            // @todo This should be templated
            var $characterCountWrapper = $('<p class="character-count" />')
                    .addClass('character-count-' + $this.attr('id').split('_').join('-'))
                    .html(' Characters Left')
                    .insertAfter($this)
                    .toggleClass('hidden', maxlength > 400)
                ,
                $characterCount = $('<span />').html(maxlength).prependTo($characterCountWrapper)
            ;

            // set initial value
            $characterCount.html(maxlength);

            // when the value of the input changes, adjust the character count
            // and add classes for alert/warning to the characer count wrapper
            $this.on('keyup', function() {
                var count = maxlength - $this.val().length;
                $characterCount.html(count);
                $characterCountWrapper.toggleClass('hidden', count > 400);
                $characterCountWrapper.toggleClass('count-alert', count < maxlength / 4);
                $characterCountWrapper.toggleClass('count-warning', count < maxlength / 10);
            });
        });

        // style select boxes on non-touch-enabled devices
	var $selects = $form.find('select');
	var resizeTimeout = null;
        if (!TEACH.support.touchEnabled && !TEACH.support.loadedInIframe) {
	    $selects.customSelect();
	    $(window).on('resize', function() {
		clearTimeout (resizeTimeout);

		resizeTimeout = setTimeout(function() {
		    $selects.trigger('update');
		}, 750);
	    });
        } else {
            // If we don't use styled customSelect widgets
            // the alignment is off
            $form
                    .find('.vertically-center')
                    .removeClass('vertically-center')
                    .css('display', 'block')
                    ;
        }

        // School ID field stuff
        var $schoolId = $('#school_id');
        var $schoolState = $('#school_state');
        var $schoolName = $('#school_name');
        var $schoolCity = $('#school_city');
        var nameCache = (TEACH.support.hasStorage && JSON.parse(localStorage.getItem('sysSchoolCache'))) || {};

        var $schoolNameMessage = $('<p class="character-count" />')
                .addClass('character-count-school-name')
                .insertAfter($schoolName)
                ;

        // enable/disable school name field based on state value
        $schoolState.on('change', function() {
            $schoolName.attr('disabled', $schoolState.val() === "");
        });

        // TODO delete gsid on name change
        $schoolName.on('change', function() {
            if (!$schoolName.data('autocompleteOpen')) {
                $schoolId.val('0');
		$schoolCity.val('');
            }
	}).on('blur', function() {
	    $schoolName.removeClass('in-progress');
	})

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
                        TEACH.support.hasStorage && localStorage.setItem('sysSchoolCache', JSON.stringify(nameCache));
                        response(schools);
                    }
                });
            }
        });

        // this makes file upload fields look nicer
        var $imageInputs = $form.find('.sys-image');
        var equalizeImageHeights = function() {
            var height = 0;
            $imageInputs.find('.sys-image-description').each(function() {
                var thisHeight = $(this).height();
                height = thisHeight > height ? thisHeight : height;
            }).css({minHeight: height + 'px'});
        };

        equalizeImageHeights();

        // get the Cloudinary support going
        $form.find('.sys-image').each(function() {
            var $this = $(this);
            var $file = $this.find('input[type="file"]');
            var id = $file.attr('id');

            var done = function(e, data) {
                var response = JSON.parse(data.jqXHR.responseText);
                var $id = $('#' + id + "_id").val(response.public_id);
                var $url = $('#' + id + "_link").val(response.url);

                // hide the description and get rid of anything from previous uploads.
                $this.find('.sys-image-description').hide();
                $this.find('.thumbnail, .sys-upload-buttons span:not(:first-child)').remove();

                $('<p>').addClass('thumbnail').html($.cloudinary.image(response.public_id + '.jpg', {width: 150, height: 150, crop: 'fill'})).insertAfter($this.find('p:first-child'));
                equalizeImageHeights();

                $('<span />').text('Remove').on('click', function(e) {
                    e.preventDefault();
                    e.stopPropagation();

                    $this.find('.thumbnail').remove();
                    $this.find('.sys-image-description').show();

                    $id.val('');
                    $url.val('');

                    $(this).off('click').remove();
                }).appendTo($this.find('.sys-upload-buttons'));
            };

            $file.cloudinary_fileupload({
                formData: Drupal.settings.cloudinary_support.file_field_data,
                done: done
            });
        });

        // Preview
        $form.find('#sys-preview').on('click', function(e) {
            e.preventDefault();
            if (!$form.valid()) {
                $form.find('.error').first().focus();
                return;
            }

	    var formData = parseFormData($form);

	    // replace Cloudinary values with defaults
	    if (!formData.user_image_id) {
		formData.user_image_id = 'sys-defaults/avatar';
		formData.user_image_link = $.cloudinary.url(formData.user_image_id + '.jpg');
	    }

	    if (!formData.teacher_image_id) {
		formData.teacher_image_id = 'sys-defaults/sys-default-' + Math.ceil(Math.random() * 17);
		formData.teacher_image_link = $.cloudinary.url(formData.teacher_image_id + '.jpg');
	    }

	    $modal = $(TEACH.tmpl('story_template', formData));
            $modal.find('img').cloudinary();
            $.tpmodal.show({
                id: "sys_modal_",
                node: $modal[0],
                width: Math.min(window.innerWidth, 800) + "px",
                height: Math.min(window.innerHeight, 500) + "px"
            });
        });

        $form.validate({
            submitHandler: sysFormSubmit,
            messages: {
                terms_agree: {
                    required: "You must agree to to submit your story."
                }
            }
        });

    }); // $(document).ready() callback

})(jQuery, TEACH, this, this.document)
