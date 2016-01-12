<div id="comments-<?php print $variables['nid']; ?>">
  <a class="comments-count"><span class="icon i-chat-bubble"></span>
    Show Comments (<span class="fb-comments-count" data-href="<?php print $variables['url']; ?>"></span>)</a>

</div>
<script type="text/javascript">
jQuery(document).ready(function(){
  var commentsid = jQuery("#comments-<?php print $variables['nid']; ?>");

  var width = 320;
  if (window.innerWidth > 480) {
    width = 640;
  }

  commentsid.append("<div class=\"fb-comments\" data-href=\"<?php print $variables['url']; ?>\" data-numposts=\"1\" data-version=\"v2.3\" data-width=\""+width+"\"></div>")
  if(typeof FB != 'undefined') {
    FB.XFBML.parse(document.getElementById("comments-<?php print $variables['nid']; ?>"));
  }
});
</script>
