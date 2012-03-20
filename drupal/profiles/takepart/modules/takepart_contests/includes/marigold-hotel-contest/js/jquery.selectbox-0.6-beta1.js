/*
 * jQuery selectbox plugin
 *
 * Copyright (c) 2007 Sadri Sahraoui (brainfault.com)
 * Licensed under the GPL license and MIT:
 *   http://www.opensource.org/licenses/GPL-license.php
 *   http://www.opensource.org/licenses/mit-license.php
 *
 * The code is inspired from Autocomplete plugin (http://www.dyve.net/jquery/?autocomplete)
 *
 * Revision: $Id$
 * Version: 0.6
 * 
 * Changelog :
 *  Version 0.6
 *  - Fix IE scrolling problem
 *  Version 0.5 
 *  - separate css style for current selected element and hover element which solve the highlight issue 
 *  Version 0.4
 *  - Fix width when the select is in a hidden div   @Pawel Maziarz
 *  - Add a unique id for generated li to avoid conflict with other selects and empty values @Pawel Maziarz
 */
/* pawel maziarz: work around for ie logging */
if (!window.console) {
	var console = {
		log: function(msg) { 
	 }
	};
}
/* */
(function($){
$.fn.extend({
	selectbox: function(options) {
		return this.each(function() {
			new $.SelectBox(this, options);
		});
	}
});
$.SelectBox = function(selectobj, options) {
	
	var opt = $.extend(options, {
		inputClass: "selectbox",
		containerClass: "selectbox-wrapper",
		hoverClass: "current",
		selectedClass: "selected",
		debug: false
	});
	
	
	var elm_id = selectobj.id;
	var active = 0;
	var inFocus = false;
	var hasfocus = 0;
	
	var widget_id = new Date().getTime();
	
	//jquery object for select element
	var $select = $(selectobj);
	// jquery container object
	var $container = setupContainer();
	//jquery input object 
	var $input = setupInput();
	// hide select and append newly created elements
	$select.hide().attr('aria-hidden', true).before($input).before($container);
	
	
	init();
	
	$input
	.click(function(){
    if (!inFocus) {
		  $container.toggle();
		}
	})
	.focus(function(){
	   if ($container.not(':visible')) {
	       inFocus = true;
	       $container.show();
		   var activeLi = $('li.'+opt.selectedClass,$container)||$('li:first',$container);
		   activeLi.addClass(opt.hoverClass).attr("aria-selected", true)[0].scrollIntoView(true);
		   $input.attr({'aria-expanded': true,'aria-activedescendant': activeLi[0].id});
		   
	   }
	})
	.keydown(function(event) {	   
		switch(event.keyCode) {
			
			case 38: // up
				event.preventDefault();
				moveSelect(-1);
				break;
			case 40: // down
				event.preventDefault();
				moveSelect(1);
				break;
			//case 9:  // tab 
			case 13: // return
				event.preventDefault(); // seems not working in mac !
				$('li.'+opt.hoverClass, $container[0]).trigger('click');
				return false;
			case 27: //escape
			  hideMe();
			  break;
		}
	})
	.blur(function() {
		if ($container.is(':visible') && hasfocus > 0 ) {
			if(opt.debug) console.log('container visible and has focus');
		} else {
		  // Workaround for ie scroll - thanks to Bernd Matzner
		  if($.browser.msie || $.browser.safari){ // check for safari too - workaround for webkit
	        if(document.activeElement.getAttribute('id').indexOf('_container')==-1){
	          hideMe();
	        } else {
	          $input.focus();
	        }
      } else {
        hideMe();
      }
		}
	});


	function hideMe() { 
		hasfocus = 0;
		$input.attr('aria-expanded', false);
		$container.hide(); 
	}
	
	function init() {
		$container.append(getSelectOptions($input.attr('id'))).hide();
		var width = $input.css('width');
		$container.width(width);
    }
	
	function setupContainer() {
		var container = document.createElement("div");
		$container = $(container);
		$container.attr('id', elm_id+'_container');
		$container.addClass(opt.containerClass);
		
		return $container;
	}
	
	function setupInput() {
		var input = document.createElement("input");
			
		var $input = $(input);
		var label = $('label[for='+selectobj.id+']');
		$input.attr({
			"id": elm_id+"_input",
			"type": "text",
			"autocomplete": "off",
			"readonly": "readonly",
			"tabIndex": $select.attr("tabindex"), // "I" capital is important for ie
			"aria-owns": $container.attr('id'),
			"role": "select",
			"aria-expanded": false
		}).addClass(opt.inputClass);
		if(label[0]){
			var id = label.attr('id') || 'label-'+widget_id;
			label.attr('id', id);
			$input.attr('aria-labelledby', id);
		}
		return $input;	
	}
	
	function moveSelect(step) {
		var lis = $("li", $container);
		if (!lis) return false;
		active += step;
    //loop through list
		if (active < 0) {
			active = lis.size()-1;
		} else if (active >= lis.size()) {
			active = 0;
		}
    	//scroll(lis, active);

		lis.filter('.'+opt.hoverClass).removeClass(opt.hoverClass)
			.attr('aria-selected', false);
		var activeLi = $(lis[active]).addClass(opt.hoverClass).attr('aria-selected', true);
		$input.attr('aria-activedescendant', activeLi.attr('id'));
		activeLi[0].scrollIntoView(true);
	}
	/*
	function scroll(list, active) {
      var el = $(list[active]).get(0);
      list = $container.get(0);
      
      if (el.offsetTop + el.offsetHeight > list.scrollTop + list.clientHeight) {
        list.scrollTop = el.offsetTop + el.offsetHeight - list.clientHeight;      
      } else if(el.offsetTop < list.scrollTop) {
        list.scrollTop = el.offsetTop;
      }
	}
	*/
	function setCurrent() {	
		var li = $("li."+opt.selectedClass, $container);
		$select.val($.data(li[0], 'selectboxval'));
		$input.val(li.html());
		$select.triggerHandler('change');
		return true;
	}
	
	// select value
	function getCurrentSelected() {
		return $select.val();
	}
	
	// input value
	function getCurrentValue() {
		return $input.val();
	}
	
	function getSelectOptions(parentid) {
		var select_options = [];
		var ul = document.createElement('ul');
		$select.children('option').each(function(i) {
			var li = document.createElement('li');
			li.setAttribute('id', parentid + '_' + i);
			li.innerHTML = $(this).html();
			li = $(li).attr({
				"role": "option",
				"aria-checked": false,
				"aria-selected": false
			});
			
			$.data(li[0], 'selectboxval', this.value || this.text);
			
			if ($(this).is(':selected')) {
				$input.val($(this).html());
				li.addClass(opt.selectedClass).attr({
					"aria-checked": true,
					"aria-selected": true
				});
				active = i;
			}
			ul.appendChild(li[0]);
			ul.setAttribute('role', 'presentation');
			li
			.mouseover(function(event) {
				hasfocus = 1;
				if (opt.debug) console.log('over on : '+this.id);
				$input.attr("activedescendant", this.id);
				$(event.target).addClass(opt.hoverClass)
					.attr('aria-selected', true);
			})
			.mouseout(function(event) {
				hasfocus = -1;
				if (opt.debug) console.log('out on : '+this.id);
				$(event.target).removeClass(opt.hoverClass)
					.attr('aria-selected', false);
			})
			.click(function(event) {
			  var fl = $('li.'+opt.hoverClass, $container).get(0);
				if (opt.debug) console.log('click on :'+this.id);
				$('li.'+opt.selectedClass, $container[0]).removeClass(opt.currentClass)
					.attr('aria-checked', false); 
				$(this).addClass(opt.selectedClass)
					.attr('aria-checked', true);
				setCurrent();
				$select.get(0).blur();
				hideMe();
			});
		});
		return ul;
	}
};
})(jQuery);
