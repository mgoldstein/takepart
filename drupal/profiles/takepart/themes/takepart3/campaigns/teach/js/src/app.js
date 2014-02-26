(function($, window, document, undefined){

  // tap values that may change
  var TAP = {
    postURL: "http://qa-web1.tab.takepart.com/user_teach_stories",
    action_id: "9035072",
    partner_code: "8e42f2980097d0f37462d2539122b698"
  };

  var touchEnabled = 'ontouchstart' in window || window.DocumentTouch && document instanceof DocumentTouch;

  var coppaCookieName = "pm_sys_user_birthdate",
      coppaCookieExpires = 1, // days to keep the cookie
      msDay = 24 * 60 * 60 * 1000, // one day in milliseconds
      ageRequirement = Date.now() - 13 * 365 * msDay; // 13 years in milliseconds

  // Simple JavaScript Templating
  // John Resig - http://ejohn.org/ - MIT Licensed
  var templateCache = {};

  var tmpl = function tmpl(str, data){
    // Figure out if we're getting a template, or if we need to
    // load the template - and be sure to cache the result.
    var fn = !/\W/.test(str) ?
      templateCache[str] = templateCache[str] ||
        tmpl(document.getElementById(str).innerHTML) :
     
      // Generate a reusable function that will serve as a template
      // generator (and which will be cached).
      new Function("obj",
        "var p=[],print=function(){p.push.apply(p,arguments);};" +
       
        // Introduce the data as local variables using with(){}
        "with(obj){p.push('" +
       
        // Convert the template into pure JavaScript
        str
          .replace(/[\r\t\n]/g, " ")
          .split("<%").join("\t")
          .replace(/((^|%>)[^\t]*)'/g, "$1\r")
          .replace(/\t=(.*?)%>/g, "',$1,'")
          .split("\t").join("');")
          .split("%>").join("p.push('")
          .split("\r").join("\\'")
      + "');}return p.join('');");
   
    // Provide some basic currying to the user
    return data ? fn( data ) : fn;
  };

  String.prototype.htmlEntities = function() {
      return this.replace(/&/g, '&amp;').replace(/</g, '&lt;').replace(/>/g, '&gt;').replace(/"/g, '&quot;');
  }

  // polyfill for String.trim()
  if (!String.prototype.trim) {
    String.prototype.trim = function () {
      return this.replace(/^\s+|\s+$/g, '');
    };
  }

  // show coppa error message and delete form from page
  var showCoppaErrorMessage = function() {
      $('#sys-form-content').slideUp().remove();
      $('#sys-coppa-content').slideDown();
  };

  var sysFormSubmit = function(form) {
    var $form = $(form);
    var formData = parseFormData($form);

    var userBirthdate = formData.user_year + '-' + formData.user_month + '-' + formData.user_day;

    if (Date.parse(userBirthdate) > ageRequirement) {

      // set coppa cookie
      var expires = new Date();
      expires.setTime(expires.getTime() + coppaCookieExpires * msDay);
      document.cookie = escape(coppaCookieName) + "=" + escape(userBirthdate) + "; expires=" +  expires.toGMTString() + '; path=/';

      showCoppaErrorMessage();

      return false;
    }

    // we've passed the age check. Lets have a beer.

    var json = {
      "format": "json",
      "action_id": TAP.action_id,
      "opt_ins": {},
      "user_action": {
        "partner_code": TAP.partner_code,
        "email": formData.email,
        "last_name": formData.first_name,
        "first_name": formData.last_name,
	"image_link": formData.user_image_link,
	"image_uid": formData.user_image_id,

        // boilerplate
        "zip":"90210",
        "state":"CA",
        "city":"Beverly Hills",
        "address":"331 Foothill Rd."
      },
      "story": {
        "year": formData.story_year,
        "preview": "",
        "title": formData.story_title,
        "body": formData.story_body
      },

      "teacher": {
        "first_name": formData.teacher_first_name,
        "last_name":  formData.teacher_last_name,
	"image_link": formData.teacher_image_link,
	"image_uid": formData.teacher_image_id
      },
      "school": {
	"name": formData.school_name,
	"city": formData.school_city,
	"state": formData.school_state,
        "external_id": formData.school_id
      }
    };

    if (formData.email_subscribe == true) {
      json.opt_ins.teach_campaign = "true";
    }

    $.ajax({
      type: 'POST',
      url: TAP.postURL,
      data: JSON.stringify(json),
      contentType: 'application/json',
      dataType: 'json',
      success: function(data, textStatus, jqXHR) {
        $('#sys-form-content').slideUp().remove();
        $('#sys-thanks-content').slideDown();

        // todo remove before deploy
        console.log(json);
        console.log(data);
        console.log(textStatus);
        console.log(jqXHR);
      }
    });

  };

  var parseFormData = function($form) {
    var formData = {};
    $form.find("input, textarea, select").not('[type="checkbox"], [type="file"]').each(function() {
      // @see String.prototype.htmlEntities
      formData[this.id] = $(this).val().trim().replace(/\n+/g, ' ').htmlEntities();
    });

    // get more useful checkbox values
    formData.email_subscribe = $form.find('#email_subscribe').is(':checked');
    formData.terms_agree = $form.find('#terms_agree').is(':checked');

    console.log(formData); // TODO Remove this before launch!
    return formData;
  };

  // not using Drupal.behaviors because this JS has nothing to do with drupal
  $(document).ready(function() {

    // coppa check
    var birthDate = null;
    $.each(document.cookie.split(";"), function() {
      if (this.trim().indexOf(escape(coppaCookieName)) === 0) {
        birthDate = unescape(this.substring(escape(coppaCookieName).length + 1, this.length));
      }
    });
    if (birthDate && (Date.parse(birthDate) > ageRequirement)) {
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
        $characterCountWrapper.toggleClass('count-alert', count < maxlength / 4);
        $characterCountWrapper.toggleClass('count-warning', count < maxlength / 10);
      });
    });

    // style select boxes on non-touch-enabled devices
    if (!touchEnabled) {
        $form.find('select').customSelect();
    }

    // School ID field stuff
    var $schoolId = $('#school_id');
    var $schoolState = $('#school_state');
    var $schoolName = $('#school_name');
    var $schoolCity = $('#school_city');
    var nameCache = {}; // TODO html5 localstorage

    // enable/disable school name field based on state value
    $schoolState.on('change', function() {
      $schoolName.attr('disabled', $schoolState.val() === "");
    });

    // TODO delete gsid on name change

    var updateSchoolFields = function(e, ui) {
      $schoolName.val(ui.item.label.split(' (')[0]);
      $schoolId.val(ui.item.value.school_id);
      $schoolCity.val(ui.item.value.school_city);
      return false; // prevent default behaivor
    };
    $schoolName.autocomplete({
      minLength: 4,
      select: updateSchoolFields,
      focus: updateSchoolFields,
      source: function(request, response) {

        var hash = encodeURIComponent('&state=' + $schoolState.val() + '&q=' + request.term);
        if (hash in nameCache) {
          response(nameCache[hash]);
          return;
        }

        $.ajax({
          url: '/proxy?request=' + encodeURIComponent('http://api.greatschools.org/search/schools/?key=zzlcyx4aijxe1nmnagoziqxx') + hash,
          success: function (data, textStatus, jqXHR) {
            var schools = [];
            $(data).find('school').each(function(){
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
	    response(schools);
          }
        });
      }
    });

    // this makes file upload fields look nicer
    var $imageInputs = $form.find('.sys-image');
    var equalizeImageHeights = function(){
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

	$this.find('.sys-image-description').hide();

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
      if (!$form.valid()) return;
      $modal = $(tmpl('story_template', parseFormData($form)));
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

})(jQuery, this, this.document)
