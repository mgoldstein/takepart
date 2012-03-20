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
 * Version: 0.5
 * 
 * Changelog :
 *  Version 0.5 
 *  - separate css style for current selected element and hover element which solve the highlight issue 
 *  Version 0.4
 *  - Fix width when the select is in a hidden div   @Pawel Maziarz
 *  - Add a unique id for generated li to avoid conflict with other selects and empty values @Pawel Maziarz
 */
jQuery.fn.extend({
	selectbox: function(options) {
		return this.each(function() {
			new jQuery.SelectBox(this, options);
		});
	}
});


/* pawel maziarz: work around for ie logging */
if (!window.console) {
	var console = {
		log: function(msg) { 
	 }
	};
}
/* */

jQuery.SelectBox = function(selectobj, options) {
	
	var opt = options || {};
	opt.inputClass = opt.inputClass || "selectbox";
	opt.containerClass = opt.containerClass || "selectbox-wrapper";
	opt.hoverClass = opt.hoverClass || "current";
	opt.currentClass = opt.selectedClass || "selected";
	opt.debug = opt.debug || false;
	
	var elm_id = selectobj.id;
	var widget_id = new Date().getTime();
	var active = -1;
	var inFocus = false;
	var hasfocus = 0;
	//jquery object for select element
	var $select = $(selectobj);
	// jquery container object
	var $container = setupContainer(opt);
	//jquery input object 
	var $input = setupInput(opt);
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
	       $container.fadeIn("fast");
		   var activeLi = $('li.'+opt.currentClass,$container)[0]||$('li:first',$container)[0];
		   activeLi.setAttribute("aria-selected", true);
		   $input.attr({'aria-expanded': true,'aria-activedescendant': activeLi.id});//.slideToggle("show");
	       // custom to ui site
				 //updateDownloadFileSize();
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
				$('li.'+opt.hoverClass, $container).trigger('click');
				break;
			case 27: //escape
			  hideMe();
			  break;
		}
	})
	.blur(function() {
		if ($container.is(':visible') && hasfocus > 0 ) {
			if(opt.debug) console.log('container visible and has focus');
		} else {
			hideMe();	
		}
	});


	function hideMe() { 
		hasfocus = 0;
		$input.attr('aria-expanded', false);
		$container.fadeOut("fast");//.slideToggle("hide");
		// custom to ui site
		//updateDownloadFileSize();
	}
	
	function init() {
		$container.append(getSelectOptions($input.attr('id'))).hide();
		var width = $input.outerWidth();
		$container.width(width);
    }
	
	function setupContainer(options) {
		var container = document.createElement("div");
		$container = $(container);
		$container.attr('id', elm_id+'_container');
		$container.addClass(options.containerClass);
		
		return $container;
	}
	
	function setupInput(options) {
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
		});
		if(label[0]){
			var id = label.attr('id') || 'label-'+widget_id;
			label.attr('id', id);
			$input.attr('aria-labelledby', id);
		}
		$input.addClass(options.inputClass);
		
		
		return $input;	
	}
	
	function moveSelect(step) {
		var lis = $("li", $container);
		
		if (!lis) return;

		active += step;
		
		if (active < 0) {
			active = 0;
		} else if (active >= lis.size()) {
			active = lis.size() - 1;
		}

		lis.filter('.'+opt.hoverClass).removeClass(opt.hoverClass)
			.attr('aria-selected', false);
		var activeLi = $(lis[active]).addClass(opt.hoverClass).attr('aria-selected', true);
		$input.attr('aria-activedescendant', activeLi.attr('id'));
	}
	
	function setCurrent() {	
		var li = $("li."+opt.currentClass, $container).get(0);
		var ar = (''+li.id).split('_');
		var el = ar[ar.length-1];
		$select.val(el);
		$input.val($(li).html());
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
		$select.children('option').each(function() {
			var li = document.createElement('li');
			li.setAttribute('id', parentid + '_' + $(this).val());
			li.innerHTML = $(this).html();
			li = $(li).attr({
				"role": "option",
				"aria-checked": false,
				"aria-selected": false
			});
			if ($(this).is(':selected')) {
				$input.val($(this).html());
				li.addClass(opt.currentClass).attr({
					"aria-checked": true,
					"aria-selected": true
				});
			}
			ul.appendChild(li[0]);
			li
			.mouseover(function(event) {
				hasfocus = 1;
				if (opt.debug) console.log('over on : '+this.id);
				$input.attr("activedescendant", this.id);
				jQuery(event.target).addClass(opt.hoverClass)
					.attr('aria-selected', true);
			})
			.mouseout(function(event) {
				hasfocus = -1;
				if (opt.debug) console.log('out on : '+this.id);
				jQuery(event.target).removeClass(opt.hoverClass)
					.attr('aria-selected', false);
			})
			.click(function(event) {
			  var fl = $('li.'+opt.hoverClass, $container).get(0);
				if (opt.debug) console.log('click on :'+this.id);
				$('li.'+opt.currentClass).removeClass(opt.currentClass)
					.attr('aria-checked', false); 
				$(this).addClass(opt.currentClass)
					.attr('aria-checked', true);
				setCurrent();
				hideMe();
			});
		});
		return ul;
	}
	
};
