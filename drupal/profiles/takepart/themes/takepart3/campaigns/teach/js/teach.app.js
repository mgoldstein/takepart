/*! teach - v0.1.0 - 2014-03-04 */
!function(a){a.extend(a.fn,{validate:function(b){if(!this.length)return void(b&&b.debug&&window.console&&console.warn("Nothing selected, can't validate, returning nothing."));var c=a.data(this[0],"validator");return c?c:(this.attr("novalidate","novalidate"),c=new a.validator(b,this[0]),a.data(this[0],"validator",c),c.settings.onsubmit&&(this.validateDelegate(":submit","click",function(b){c.settings.submitHandler&&(c.submitButton=b.target),a(b.target).hasClass("cancel")&&(c.cancelSubmit=!0),void 0!==a(b.target).attr("formnovalidate")&&(c.cancelSubmit=!0)}),this.submit(function(b){function d(){var d;return c.settings.submitHandler?(c.submitButton&&(d=a("<input type='hidden'/>").attr("name",c.submitButton.name).val(a(c.submitButton).val()).appendTo(c.currentForm)),c.settings.submitHandler.call(c,c.currentForm,b),c.submitButton&&d.remove(),!1):!0}return c.settings.debug&&b.preventDefault(),c.cancelSubmit?(c.cancelSubmit=!1,d()):c.form()?c.pendingRequest?(c.formSubmitted=!0,!1):d():(c.focusInvalid(),!1)})),c)},valid:function(){if(a(this[0]).is("form"))return this.validate().form();var b=!0,c=a(this[0].form).validate();return this.each(function(){b=b&&c.element(this)}),b},removeAttrs:function(b){var c={},d=this;return a.each(b.split(/\s/),function(a,b){c[b]=d.attr(b),d.removeAttr(b)}),c},rules:function(b,c){var d=this[0];if(b){var e=a.data(d.form,"validator").settings,f=e.rules,g=a.validator.staticRules(d);switch(b){case"add":a.extend(g,a.validator.normalizeRule(c)),delete g.messages,f[d.name]=g,c.messages&&(e.messages[d.name]=a.extend(e.messages[d.name],c.messages));break;case"remove":if(!c)return delete f[d.name],g;var h={};return a.each(c.split(/\s/),function(a,b){h[b]=g[b],delete g[b]}),h}}var i=a.validator.normalizeRules(a.extend({},a.validator.classRules(d),a.validator.attributeRules(d),a.validator.dataRules(d),a.validator.staticRules(d)),d);if(i.required){var j=i.required;delete i.required,i=a.extend({required:j},i)}return i}}),a.extend(a.expr[":"],{blank:function(b){return!a.trim(""+a(b).val())},filled:function(b){return!!a.trim(""+a(b).val())},unchecked:function(b){return!a(b).prop("checked")}}),a.validator=function(b,c){this.settings=a.extend(!0,{},a.validator.defaults,b),this.currentForm=c,this.init()},a.validator.format=function(b,c){return 1===arguments.length?function(){var c=a.makeArray(arguments);return c.unshift(b),a.validator.format.apply(this,c)}:(arguments.length>2&&c.constructor!==Array&&(c=a.makeArray(arguments).slice(1)),c.constructor!==Array&&(c=[c]),a.each(c,function(a,c){b=b.replace(new RegExp("\\{"+a+"\\}","g"),function(){return c})}),b)},a.extend(a.validator,{defaults:{messages:{},groups:{},rules:{},errorClass:"error",validClass:"valid",errorElement:"label",focusInvalid:!0,errorContainer:a([]),errorLabelContainer:a([]),onsubmit:!0,ignore:":hidden",ignoreTitle:!1,onfocusin:function(a){this.lastActive=a,this.settings.focusCleanup&&!this.blockFocusCleanup&&(this.settings.unhighlight&&this.settings.unhighlight.call(this,a,this.settings.errorClass,this.settings.validClass),this.addWrapper(this.errorsFor(a)).hide())},onfocusout:function(a){this.checkable(a)||!(a.name in this.submitted)&&this.optional(a)||this.element(a)},onkeyup:function(a,b){(9!==b.which||""!==this.elementValue(a))&&(a.name in this.submitted||a===this.lastElement)&&this.element(a)},onclick:function(a){a.name in this.submitted?this.element(a):a.parentNode.name in this.submitted&&this.element(a.parentNode)},highlight:function(b,c,d){"radio"===b.type?this.findByName(b.name).addClass(c).removeClass(d):a(b).addClass(c).removeClass(d)},unhighlight:function(b,c,d){"radio"===b.type?this.findByName(b.name).removeClass(c).addClass(d):a(b).removeClass(c).addClass(d)}},setDefaults:function(b){a.extend(a.validator.defaults,b)},messages:{required:"This field is required.",remote:"Please fix this field.",email:"Please enter a valid email address.",url:"Please enter a valid URL.",date:"Please enter a valid date.",dateISO:"Please enter a valid date (ISO).",number:"Please enter a valid number.",digits:"Please enter only digits.",creditcard:"Please enter a valid credit card number.",equalTo:"Please enter the same value again.",maxlength:a.validator.format("Please enter no more than {0} characters."),minlength:a.validator.format("Please enter at least {0} characters."),rangelength:a.validator.format("Please enter a value between {0} and {1} characters long."),range:a.validator.format("Please enter a value between {0} and {1}."),max:a.validator.format("Please enter a value less than or equal to {0}."),min:a.validator.format("Please enter a value greater than or equal to {0}.")},autoCreateRanges:!1,prototype:{init:function(){function b(b){var c=a.data(this[0].form,"validator"),d="on"+b.type.replace(/^validate/,"");c.settings[d]&&c.settings[d].call(c,this[0],b)}this.labelContainer=a(this.settings.errorLabelContainer),this.errorContext=this.labelContainer.length&&this.labelContainer||a(this.currentForm),this.containers=a(this.settings.errorContainer).add(this.settings.errorLabelContainer),this.submitted={},this.valueCache={},this.pendingRequest=0,this.pending={},this.invalid={},this.reset();var c=this.groups={};a.each(this.settings.groups,function(b,d){"string"==typeof d&&(d=d.split(/\s/)),a.each(d,function(a,d){c[d]=b})});var d=this.settings.rules;a.each(d,function(b,c){d[b]=a.validator.normalizeRule(c)}),a(this.currentForm).validateDelegate(":text, [type='password'], [type='file'], select, textarea, [type='number'], [type='search'] ,[type='tel'], [type='url'], [type='email'], [type='datetime'], [type='date'], [type='month'], [type='week'], [type='time'], [type='datetime-local'], [type='range'], [type='color'] ","focusin focusout keyup",b).validateDelegate("[type='radio'], [type='checkbox'], select, option","click",b),this.settings.invalidHandler&&a(this.currentForm).bind("invalid-form.validate",this.settings.invalidHandler)},form:function(){return this.checkForm(),a.extend(this.submitted,this.errorMap),this.invalid=a.extend({},this.errorMap),this.valid()||a(this.currentForm).triggerHandler("invalid-form",[this]),this.showErrors(),this.valid()},checkForm:function(){this.prepareForm();for(var a=0,b=this.currentElements=this.elements();b[a];a++)this.check(b[a]);return this.valid()},element:function(b){b=this.validationTargetFor(this.clean(b)),this.lastElement=b,this.prepareElement(b),this.currentElements=a(b);var c=this.check(b)!==!1;return c?delete this.invalid[b.name]:this.invalid[b.name]=!0,this.numberOfInvalids()||(this.toHide=this.toHide.add(this.containers)),this.showErrors(),c},showErrors:function(b){if(b){a.extend(this.errorMap,b),this.errorList=[];for(var c in b)this.errorList.push({message:b[c],element:this.findByName(c)[0]});this.successList=a.grep(this.successList,function(a){return!(a.name in b)})}this.settings.showErrors?this.settings.showErrors.call(this,this.errorMap,this.errorList):this.defaultShowErrors()},resetForm:function(){a.fn.resetForm&&a(this.currentForm).resetForm(),this.submitted={},this.lastElement=null,this.prepareForm(),this.hideErrors(),this.elements().removeClass(this.settings.errorClass).removeData("previousValue")},numberOfInvalids:function(){return this.objectLength(this.invalid)},objectLength:function(a){var b=0;for(var c in a)b++;return b},hideErrors:function(){this.addWrapper(this.toHide).hide()},valid:function(){return 0===this.size()},size:function(){return this.errorList.length},focusInvalid:function(){if(this.settings.focusInvalid)try{a(this.findLastActive()||this.errorList.length&&this.errorList[0].element||[]).filter(":visible").focus().trigger("focusin")}catch(b){}},findLastActive:function(){var b=this.lastActive;return b&&1===a.grep(this.errorList,function(a){return a.element.name===b.name}).length&&b},elements:function(){var b=this,c={};return a(this.currentForm).find("input, select, textarea").not(":submit, :reset, :image, [disabled]").not(this.settings.ignore).filter(function(){return!this.name&&b.settings.debug&&window.console&&console.error("%o has no name assigned",this),this.name in c||!b.objectLength(a(this).rules())?!1:(c[this.name]=!0,!0)})},clean:function(b){return a(b)[0]},errors:function(){var b=this.settings.errorClass.replace(" ",".");return a(this.settings.errorElement+"."+b,this.errorContext)},reset:function(){this.successList=[],this.errorList=[],this.errorMap={},this.toShow=a([]),this.toHide=a([]),this.currentElements=a([])},prepareForm:function(){this.reset(),this.toHide=this.errors().add(this.containers)},prepareElement:function(a){this.reset(),this.toHide=this.errorsFor(a)},elementValue:function(b){var c=a(b).attr("type"),d=a(b).val();return"radio"===c||"checkbox"===c?a("input[name='"+a(b).attr("name")+"']:checked").val():"string"==typeof d?d.replace(/\r/g,""):d},check:function(b){b=this.validationTargetFor(this.clean(b));var c,d=a(b).rules(),e=!1,f=this.elementValue(b);for(var g in d){var h={method:g,parameters:d[g]};try{if(c=a.validator.methods[g].call(this,f,b,h.parameters),"dependency-mismatch"===c){e=!0;continue}if(e=!1,"pending"===c)return void(this.toHide=this.toHide.not(this.errorsFor(b)));if(!c)return this.formatAndAdd(b,h),!1}catch(i){throw this.settings.debug&&window.console&&console.log("Exception occurred when checking element "+b.id+", check the '"+h.method+"' method.",i),i}}return e?void 0:(this.objectLength(d)&&this.successList.push(b),!0)},customDataMessage:function(b,c){return a(b).data("msg-"+c.toLowerCase())||b.attributes&&a(b).attr("data-msg-"+c.toLowerCase())},customMessage:function(a,b){var c=this.settings.messages[a];return c&&(c.constructor===String?c:c[b])},findDefined:function(){for(var a=0;a<arguments.length;a++)if(void 0!==arguments[a])return arguments[a];return void 0},defaultMessage:function(b,c){return this.findDefined(this.customMessage(b.name,c),this.customDataMessage(b,c),!this.settings.ignoreTitle&&b.title||void 0,a.validator.messages[c],"<strong>Warning: No message defined for "+b.name+"</strong>")},formatAndAdd:function(b,c){var d=this.defaultMessage(b,c.method),e=/\$?\{(\d+)\}/g;"function"==typeof d?d=d.call(this,c.parameters,b):e.test(d)&&(d=a.validator.format(d.replace(e,"{$1}"),c.parameters)),this.errorList.push({message:d,element:b}),this.errorMap[b.name]=d,this.submitted[b.name]=d},addWrapper:function(a){return this.settings.wrapper&&(a=a.add(a.parent(this.settings.wrapper))),a},defaultShowErrors:function(){var a,b;for(a=0;this.errorList[a];a++){var c=this.errorList[a];this.settings.highlight&&this.settings.highlight.call(this,c.element,this.settings.errorClass,this.settings.validClass),this.showLabel(c.element,c.message)}if(this.errorList.length&&(this.toShow=this.toShow.add(this.containers)),this.settings.success)for(a=0;this.successList[a];a++)this.showLabel(this.successList[a]);if(this.settings.unhighlight)for(a=0,b=this.validElements();b[a];a++)this.settings.unhighlight.call(this,b[a],this.settings.errorClass,this.settings.validClass);this.toHide=this.toHide.not(this.toShow),this.hideErrors(),this.addWrapper(this.toShow).show()},validElements:function(){return this.currentElements.not(this.invalidElements())},invalidElements:function(){return a(this.errorList).map(function(){return this.element})},showLabel:function(b,c){var d=this.errorsFor(b);d.length?(d.removeClass(this.settings.validClass).addClass(this.settings.errorClass),d.html(c)):(d=a("<"+this.settings.errorElement+">").attr("for",this.idOrName(b)).addClass(this.settings.errorClass).html(c||""),this.settings.wrapper&&(d=d.hide().show().wrap("<"+this.settings.wrapper+"/>").parent()),this.labelContainer.append(d).length||(this.settings.errorPlacement?this.settings.errorPlacement(d,a(b)):d.insertAfter(b))),!c&&this.settings.success&&(d.text(""),"string"==typeof this.settings.success?d.addClass(this.settings.success):this.settings.success(d,b)),this.toShow=this.toShow.add(d)},errorsFor:function(b){var c=this.idOrName(b);return this.errors().filter(function(){return a(this).attr("for")===c})},idOrName:function(a){return this.groups[a.name]||(this.checkable(a)?a.name:a.id||a.name)},validationTargetFor:function(a){return this.checkable(a)&&(a=this.findByName(a.name).not(this.settings.ignore)[0]),a},checkable:function(a){return/radio|checkbox/i.test(a.type)},findByName:function(b){return a(this.currentForm).find("[name='"+b+"']")},getLength:function(b,c){switch(c.nodeName.toLowerCase()){case"select":return a("option:selected",c).length;case"input":if(this.checkable(c))return this.findByName(c.name).filter(":checked").length}return b.length},depend:function(a,b){return this.dependTypes[typeof a]?this.dependTypes[typeof a](a,b):!0},dependTypes:{"boolean":function(a){return a},string:function(b,c){return!!a(b,c.form).length},"function":function(a,b){return a(b)}},optional:function(b){var c=this.elementValue(b);return!a.validator.methods.required.call(this,c,b)&&"dependency-mismatch"},startRequest:function(a){this.pending[a.name]||(this.pendingRequest++,this.pending[a.name]=!0)},stopRequest:function(b,c){this.pendingRequest--,this.pendingRequest<0&&(this.pendingRequest=0),delete this.pending[b.name],c&&0===this.pendingRequest&&this.formSubmitted&&this.form()?(a(this.currentForm).submit(),this.formSubmitted=!1):!c&&0===this.pendingRequest&&this.formSubmitted&&(a(this.currentForm).triggerHandler("invalid-form",[this]),this.formSubmitted=!1)},previousValue:function(b){return a.data(b,"previousValue")||a.data(b,"previousValue",{old:null,valid:!0,message:this.defaultMessage(b,"remote")})}},classRuleSettings:{required:{required:!0},email:{email:!0},url:{url:!0},date:{date:!0},dateISO:{dateISO:!0},number:{number:!0},digits:{digits:!0},creditcard:{creditcard:!0}},addClassRules:function(b,c){b.constructor===String?this.classRuleSettings[b]=c:a.extend(this.classRuleSettings,b)},classRules:function(b){var c={},d=a(b).attr("class");return d&&a.each(d.split(" "),function(){this in a.validator.classRuleSettings&&a.extend(c,a.validator.classRuleSettings[this])}),c},attributeRules:function(b){var c={},d=a(b),e=d[0].getAttribute("type");for(var f in a.validator.methods){var g;"required"===f?(g=d.get(0).getAttribute(f),""===g&&(g=!0),g=!!g):g=d.attr(f),/min|max/.test(f)&&(null===e||/number|range|text/.test(e))&&(g=Number(g)),g?c[f]=g:e===f&&"range"!==e&&(c[f]=!0)}return c.maxlength&&/-1|2147483647|524288/.test(c.maxlength)&&delete c.maxlength,c},dataRules:function(b){var c,d,e={},f=a(b);for(c in a.validator.methods)d=f.data("rule-"+c.toLowerCase()),void 0!==d&&(e[c]=d);return e},staticRules:function(b){var c={},d=a.data(b.form,"validator");return d.settings.rules&&(c=a.validator.normalizeRule(d.settings.rules[b.name])||{}),c},normalizeRules:function(b,c){return a.each(b,function(d,e){if(e===!1)return void delete b[d];if(e.param||e.depends){var f=!0;switch(typeof e.depends){case"string":f=!!a(e.depends,c.form).length;break;case"function":f=e.depends.call(c,c)}f?b[d]=void 0!==e.param?e.param:!0:delete b[d]}}),a.each(b,function(d,e){b[d]=a.isFunction(e)?e(c):e}),a.each(["minlength","maxlength"],function(){b[this]&&(b[this]=Number(b[this]))}),a.each(["rangelength","range"],function(){var c;b[this]&&(a.isArray(b[this])?b[this]=[Number(b[this][0]),Number(b[this][1])]:"string"==typeof b[this]&&(c=b[this].split(/[\s,]+/),b[this]=[Number(c[0]),Number(c[1])]))}),a.validator.autoCreateRanges&&(b.min&&b.max&&(b.range=[b.min,b.max],delete b.min,delete b.max),b.minlength&&b.maxlength&&(b.rangelength=[b.minlength,b.maxlength],delete b.minlength,delete b.maxlength)),b},normalizeRule:function(b){if("string"==typeof b){var c={};a.each(b.split(/\s/),function(){c[this]=!0}),b=c}return b},addMethod:function(b,c,d){a.validator.methods[b]=c,a.validator.messages[b]=void 0!==d?d:a.validator.messages[b],c.length<3&&a.validator.addClassRules(b,a.validator.normalizeRule(b))},methods:{required:function(b,c,d){if(!this.depend(d,c))return"dependency-mismatch";if("select"===c.nodeName.toLowerCase()){var e=a(c).val();return e&&e.length>0}return this.checkable(c)?this.getLength(b,c)>0:a.trim(b).length>0},email:function(a,b){return this.optional(b)||/^((([a-z]|\d|[!#\$%&'\*\+\-\/=\?\^_`{\|}~]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])+(\.([a-z]|\d|[!#\$%&'\*\+\-\/=\?\^_`{\|}~]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])+)*)|((\x22)((((\x20|\x09)*(\x0d\x0a))?(\x20|\x09)+)?(([\x01-\x08\x0b\x0c\x0e-\x1f\x7f]|\x21|[\x23-\x5b]|[\x5d-\x7e]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])|(\\([\x01-\x09\x0b\x0c\x0d-\x7f]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF]))))*(((\x20|\x09)*(\x0d\x0a))?(\x20|\x09)+)?(\x22)))@((([a-z]|\d|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])|(([a-z]|\d|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])([a-z]|\d|-|\.|_|~|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])*([a-z]|\d|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])))\.)+(([a-z]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])|(([a-z]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])([a-z]|\d|-|\.|_|~|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])*([a-z]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])))$/i.test(a)},url:function(a,b){return this.optional(b)||/^(https?|s?ftp):\/\/(((([a-z]|\d|-|\.|_|~|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])|(%[\da-f]{2})|[!\$&'\(\)\*\+,;=]|:)*@)?(((\d|[1-9]\d|1\d\d|2[0-4]\d|25[0-5])\.(\d|[1-9]\d|1\d\d|2[0-4]\d|25[0-5])\.(\d|[1-9]\d|1\d\d|2[0-4]\d|25[0-5])\.(\d|[1-9]\d|1\d\d|2[0-4]\d|25[0-5]))|((([a-z]|\d|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])|(([a-z]|\d|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])([a-z]|\d|-|\.|_|~|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])*([a-z]|\d|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])))\.)+(([a-z]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])|(([a-z]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])([a-z]|\d|-|\.|_|~|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])*([a-z]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])))\.?)(:\d*)?)(\/((([a-z]|\d|-|\.|_|~|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])|(%[\da-f]{2})|[!\$&'\(\)\*\+,;=]|:|@)+(\/(([a-z]|\d|-|\.|_|~|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])|(%[\da-f]{2})|[!\$&'\(\)\*\+,;=]|:|@)*)*)?)?(\?((([a-z]|\d|-|\.|_|~|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])|(%[\da-f]{2})|[!\$&'\(\)\*\+,;=]|:|@)|[\uE000-\uF8FF]|\/|\?)*)?(#((([a-z]|\d|-|\.|_|~|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])|(%[\da-f]{2})|[!\$&'\(\)\*\+,;=]|:|@)|\/|\?)*)?$/i.test(a)},date:function(a,b){return this.optional(b)||!/Invalid|NaN/.test(new Date(a).toString())},dateISO:function(a,b){return this.optional(b)||/^\d{4}[\/\-]\d{1,2}[\/\-]\d{1,2}$/.test(a)},number:function(a,b){return this.optional(b)||/^-?(?:\d+|\d{1,3}(?:,\d{3})+)?(?:\.\d+)?$/.test(a)},digits:function(a,b){return this.optional(b)||/^\d+$/.test(a)},creditcard:function(a,b){if(this.optional(b))return"dependency-mismatch";if(/[^0-9 \-]+/.test(a))return!1;var c=0,d=0,e=!1;a=a.replace(/\D/g,"");for(var f=a.length-1;f>=0;f--){var g=a.charAt(f);d=parseInt(g,10),e&&(d*=2)>9&&(d-=9),c+=d,e=!e}return c%10===0},minlength:function(b,c,d){var e=a.isArray(b)?b.length:this.getLength(a.trim(b),c);return this.optional(c)||e>=d},maxlength:function(b,c,d){var e=a.isArray(b)?b.length:this.getLength(a.trim(b),c);return this.optional(c)||d>=e},rangelength:function(b,c,d){var e=a.isArray(b)?b.length:this.getLength(a.trim(b),c);return this.optional(c)||e>=d[0]&&e<=d[1]},min:function(a,b,c){return this.optional(b)||a>=c},max:function(a,b,c){return this.optional(b)||c>=a},range:function(a,b,c){return this.optional(b)||a>=c[0]&&a<=c[1]},equalTo:function(b,c,d){var e=a(d);return this.settings.onfocusout&&e.unbind(".validate-equalTo").bind("blur.validate-equalTo",function(){a(c).valid()}),b===e.val()},remote:function(b,c,d){if(this.optional(c))return"dependency-mismatch";var e=this.previousValue(c);if(this.settings.messages[c.name]||(this.settings.messages[c.name]={}),e.originalMessage=this.settings.messages[c.name].remote,this.settings.messages[c.name].remote=e.message,d="string"==typeof d&&{url:d}||d,e.old===b)return e.valid;e.old=b;var f=this;this.startRequest(c);var g={};return g[c.name]=b,a.ajax(a.extend(!0,{url:d,mode:"abort",port:"validate"+c.name,dataType:"json",data:g,success:function(d){f.settings.messages[c.name].remote=e.originalMessage;var g=d===!0||"true"===d;if(g){var h=f.formSubmitted;f.prepareElement(c),f.formSubmitted=h,f.successList.push(c),delete f.invalid[c.name],f.showErrors()}else{var i={},j=d||f.defaultMessage(c,"remote");i[c.name]=e.message=a.isFunction(j)?j(b):j,f.invalid[c.name]=!0,f.showErrors(i)}e.valid=g,f.stopRequest(c,g)}},d)),"pending"}}}),a.format=a.validator.format}(jQuery),function(a){var b={};if(a.ajaxPrefilter)a.ajaxPrefilter(function(a,c,d){var e=a.port;"abort"===a.mode&&(b[e]&&b[e].abort(),b[e]=d)});else{var c=a.ajax;a.ajax=function(d){var e=("mode"in d?d:a.ajaxSettings).mode,f=("port"in d?d:a.ajaxSettings).port;return"abort"===e?(b[f]&&b[f].abort(),b[f]=c.apply(this,arguments),b[f]):c.apply(this,arguments)}}}(jQuery),function(a){a.extend(a.fn,{validateDelegate:function(b,c,d){return this.bind(c,function(c){var e=a(c.target);return e.is(b)?d.apply(e,arguments):void 0})}})}(jQuery),function(a){"use strict";a.fn.extend({customSelect:function(b){if("undefined"==typeof document.body.style.maxHeight)return this;var c={customClass:"customSelect",mapClass:!0,mapStyle:!0},b=a.extend(c,b),d=b.customClass,e=function(b,c){var d=b.find(":selected"),e=c.children(":first"),g=d.html()||"&nbsp;";e.html(g),d.attr("disabled")?c.addClass(f("DisabledOption")):c.removeClass(f("DisabledOption")),setTimeout(function(){c.removeClass(f("Open")),a(document).off("mouseup."+f("Open"))},60)},f=function(a){return d+a};return this.each(function(){var c=a(this),g=a("<span />").addClass(f("Inner")),h=a("<span />");c.after(h.append(g)),h.addClass(d),b.mapClass&&h.addClass(c.attr("class")),b.mapStyle&&h.attr("style",c.attr("style")),c.addClass("hasCustomSelect").on("update",function(){e(c,h);var a=parseInt(c.outerWidth(),10)-(parseInt(h.outerWidth(),10)-parseInt(h.width(),10));h.css({display:"inline-block"});var b=h.outerHeight();c.attr("disabled")?h.addClass(f("Disabled")):h.removeClass(f("Disabled")),g.css({width:a,display:"inline-block"}),c.css({"-webkit-appearance":"menulist-button",width:h.outerWidth(),position:"absolute",opacity:0,height:b,fontSize:h.css("font-size")})}).on("change",function(){h.addClass(f("Changed")),e(c,h)}).on("keyup",function(a){h.hasClass(f("Open"))?(13==a.which||27==a.which)&&e(c,h):(c.blur(),c.focus())}).on("mousedown",function(){h.removeClass(f("Changed"))}).on("mouseup",function(b){h.hasClass(f("Open"))||(a("."+f("Open")).not(h).length>0&&"undefined"!=typeof InstallTrigger?c.focus():(h.addClass(f("Open")),b.stopPropagation(),a(document).one("mouseup."+f("Open"),function(b){b.target!=c.get(0)&&a.inArray(b.target,c.find("*").get())<0?c.blur():e(c,h)})))}).focus(function(){h.removeClass(f("Changed")).addClass(f("Focus"))}).blur(function(){h.removeClass(f("Focus")+" "+f("Open"))}).hover(function(){h.addClass(f("Hover"))},function(){h.removeClass(f("Hover"))}).trigger("update")})}})}(jQuery),function(a,b,c){var d={postURL:"http://qa-web1.tab.takepart.com/user_teach_stories",action_id:"9035092",partner_code:"38ec3cd1db216fd6964277e5969f4cb2"},e="ontouchstart"in b||b.DocumentTouch&&c instanceof DocumentTouch,f=function(){try{return localStorage.setItem("foo","test"),localStorage.removeItem("test"),!0}catch(a){return!1}}(),g=function(){try{return b.self!==b.top}catch(a){return!0}}(),h="pm_sys_user_birthdate",i=1,j=864e5,k=Date.now()-4745*j,l={},m=function q(a,b){var d=/\W/.test(a)?new Function("obj","var p=[],print=function(){p.push.apply(p,arguments);};with(obj){p.push('"+a.replace(/[\r\t\n]/g," ").split("<%").join("	").replace(/((^|%>)[^\t]*)'/g,"$1\r").replace(/\t=(.*?)%>/g,"',$1,'").split("	").join("');").split("%>").join("p.push('").split("\r").join("\\'")+"');}return p.join('');"):l[a]=l[a]||q(c.getElementById(a).innerHTML);return b?d(b):d};String.prototype.htmlEntities=function(){return this.replace(/&/g,"&amp;").replace(/</g,"&lt;").replace(/>/g,"&gt;").replace(/"/g,"&quot;")},String.prototype.trim||(String.prototype.trim=function(){return this.replace(/^\s+|\s+$/g,"")});var n=function(){a("#sys-form-content").slideUp(),a("#sys-coppa-content").removeClass("initially-hidden")},o=function(b){var e=a(b),f=p(e),g=f.user_year+"-"+f.user_month+"-"+f.user_day,l=e.find("input[type=submit]").addClass("in-progress");if(Date.parse(g)>k){var m=new Date;return m.setTime(m.getTime()+i*j),c.cookie=escape(h)+"="+escape(g)+"; expires="+m.toGMTString()+"; path=/",n(),!1}var o={format:"json",action_id:d.action_id,opt_ins:{},user_action:{partner_code:d.partner_code,email:f.email,last_name:f.first_name,first_name:f.last_name,image_link:f.user_image_link,image_uid:f.user_image_id,zip:"90210",state:"CA",city:"Beverly Hills",address:"331 Foothill Rd."},story:{year:f.story_year,preview:"",title:f.story_title,body:f.story_body},teacher:{first_name:f.teacher_first_name,last_name:f.teacher_last_name,image_link:f.teacher_image_link,image_uid:f.teacher_image_id},school:{name:f.school_name,city:f.school_city,state:f.school_state,external_id:f.school_id}};1==f.email_subscribe&&(o.opt_ins.teach_stories="true"),a.ajax({type:"POST",url:d.postURL,data:JSON.stringify(o),contentType:"application/json",dataType:"json",success:function(){a("#sys-form-content").slideUp(),a("#sys-thanks-content").removeClass("initially-hidden"),a("html, body").animate({scrollTop:a(".menu-wrapper").offset().top-25}),takepart.analytics.track("teach_story_entry")},error:function(){l.removeClass("in-progress"),alert("There was an error submitting your story.")}})},p=function(b){var c={};return b.find("input, textarea, select").not('[type="checkbox"], [type="file"]').each(function(){c[this.id]=a(this).val().trim().replace(/\n+/g," ").htmlEntities()}),c.email_subscribe=b.find("#email_subscribe").is(":checked"),c.terms_agree=b.find("#terms_agree").is(":checked"),c.user_image_id||(c.user_image_id="sys-defaults/avatar",c.user_image_link=a.cloudinary.url(c.user_image_id+".jpg"),b.find("#user_image_id").val(c.user_image_id),b.find("#user_image_link").val(c.user_image_link)),c.teacher_image_id||(c.teacher_image_id="sys-defaults/sys-default-"+Math.ceil(17*Math.random()),c.teacher_image_link=a.cloudinary.url(c.teacher_image_id+".jpg"),b.find("#teacher_image_id").val(c.teacher_image_id),b.find("#teacher_image_link").val(c.teacher_image_link)),c};a(c).ready(function(){a(b).on("tp-social-click",function(a,b){takepart.analytics.track("tp-social-click",b)}),g&&(a(".footer-wrapper, .slimnav").remove(),a("body").css("border","none"),a(".page-wrap").css("padding","0"));var d=null;if(a.each(c.cookie.split(";"),function(){0===this.trim().indexOf(escape(h))&&(d=unescape(this.substring(escape(h).length+1,this.length)))}),d&&Date.parse(d)>k)return n(),!1;var i=a("#sys-form");i.find("input[maxlength], textarea[maxlength]").each(function(){var b=a(this),c=b.attr("maxlength"),d=a('<p class="character-count" />').addClass("character-count-"+b.attr("id").split("_").join("-")).html(" Characters Left").insertAfter(b).toggleClass("hidden",c>400),e=a("<span />").html(c).prependTo(d);e.html(c),b.on("keyup",function(){var a=c-b.val().length;e.html(a),d.toggleClass("hidden",a>400),d.toggleClass("count-alert",c/4>a),d.toggleClass("count-warning",c/10>a)})});var j=i.find("select"),l=null;e||g?i.find(".vertically-center").removeClass("vertically-center").css("display","block"):(j.customSelect(),a(b).on("resize",function(){clearTimeout(l),l=setTimeout(function(){j.trigger("update")},750)}));var q=a("#school_id"),r=a("#school_state"),s=a("#school_name"),t=a("#school_city"),u=f&&JSON.parse(localStorage.getItem("sysSchoolCache"))||{},v=a('<p class="character-count" />').addClass("character-count-school-name").insertAfter(s);r.on("change",function(){s.attr("disabled",""===r.val())}),s.on("change",function(){s.data("autocompleteOpen")||(q.val("0"),t.val(""))}).on("blur",function(){s.removeClass("<in-progress></in-progress>")});var w=function(){v.removeClass("count-warning").html("")},x=function(a,b){return s.val(b.item.label.split(" (")[0]),q.val(b.item.value.school_id),t.val(b.item.value.school_city),w(),!1};s.autocomplete({minLength:4,select:x,focus:x,blur:x,search:function(){s.addClass("in-progress"),w()},open:function(){s.removeClass("in-progress").data("autocompleteOpen",!0),w()},close:function(){w(),setTimeout(function(){s.data("autocompleteOpen",!1)},1e3)},source:function(b,c){var d=encodeURIComponent("&state="+r.val()+"&q="+encodeURIComponent(b.term));return d in u?void c(u[d]):void a.ajax({url:"/proxy?request="+encodeURIComponent("http://api.greatschools.org/search/schools/?key=zzlcyx4aijxe1nmnagoziqxx")+d,error:function(){var a=["We can't find &quot;"+b.term.htmlEntities()+"&quot;.","For best results, type a single, complete word and choose from the list."];s.removeClass("in-progress"),v.addClass("count-warning").html(a.join("<br/>"))},success:function(b){var e=[];a(b).find("school").each(function(){var b=a(this);e.push({label:b.find("name").text()+" ("+b.find("city").text()+", "+b.find("state").text()+")",value:{school_id:b.find("gsId").text(),school_city:b.find("city").text(),school_state:b.find("state").text()}})}),u[d]=e,f&&localStorage.setItem("sysSchoolCache",JSON.stringify(u)),c(e)}})}});var y=i.find(".sys-image"),z=function(){var b=0;y.find(".sys-image-description").each(function(){var c=a(this).height();b=c>b?c:b}).css({minHeight:b+"px"})};z(),i.find(".sys-image").each(function(){var b=a(this),c=b.find('input[type="file"]'),d=c.attr("id"),e=function(c,e){var f=JSON.parse(e.jqXHR.responseText),g=a("#"+d+"_id").val(f.public_id),h=a("#"+d+"_link").val(f.url);b.find(".sys-image-description").hide(),b.find(".thumbnail, .sys-upload-buttons span:not(:first-child)").remove(),a("<p>").addClass("thumbnail").html(a.cloudinary.image(f.public_id+".jpg",{width:150,height:150,crop:"fill"})).insertAfter(b.find("p:first-child")),z(),a("<span />").text("Remove").on("click",function(c){c.preventDefault(),c.stopPropagation(),b.find(".thumbnail").remove(),b.find(".sys-image-description").show(),g.val(""),h.val(""),a(this).off("click").remove()}).appendTo(b.find(".sys-upload-buttons"))};c.cloudinary_fileupload({formData:Drupal.settings.cloudinary_support.file_field_data,done:e})}),i.find("#sys-preview").on("click",function(c){return c.preventDefault(),i.valid()?($modal=a(m("story_template",p(i))),$modal.find("img").cloudinary(),void a.tpmodal.show({id:"sys_modal_",node:$modal[0],width:Math.min(b.innerWidth,800)+"px",height:Math.min(b.innerHeight,500)+"px"})):void i.find(".error").first().focus()}),i.validate({submitHandler:o,messages:{terms_agree:{required:"You must agree to to submit your story."}}})})}(jQuery,this,this.document);