/*! teach - v0.2.0 */ !function(a,b,c){var d={},e=function f(a,b){var e=/\W/.test(a)?new Function("obj","var p=[],print=function(){p.push.apply(p,arguments);};with(obj){p.push('"+a.replace(/[\r\t\n]/g," ").split("<%").join("	").replace(/((^|%>)[^\t]*)'/g,"$1\r").replace(/\t=(.*?)%>/g,"',$1,'").split("	").join("');").split("%>").join("p.push('").split("\r").join("\\'")+"');}return p.join('');"):d[a]=d[a]||f(c.getElementById(a).innerHTML);return b?e(b):e};a(c).ready(function(){var b=a("#most-stories-nav"),c=a(".most-stories-list");c.hide().filter(":first").show(),b.find("a:first").addClass("active"),b.on("click","a",function(a){a.preventDefault(),b.find("a").removeClass("active").filter(this).addClass("active"),c.hide().filter(a.target.hash).show()}),a(".featured-stories").find(".featured-story").each(function(){var b=a(this);b.html(e("featured_story_template",{}))})})}(jQuery,this,this.document);