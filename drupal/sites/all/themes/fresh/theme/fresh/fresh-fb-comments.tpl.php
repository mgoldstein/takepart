<a class="comments-count"><span class="icon i-chat-bubble"></span> 
  Show Comments (<span class="fb-comments-count" data-href="<?php print $variables['url']; ?>"></span>)</a>

<div class="fb-comments" data-href="<?php print $variables['url']; ?>" data-numposts="1" data-version="v2.3" data-width="320"></div>

<script type="text/javascript">
  var fb_chat = jQuery(".fb-comments");
  if (window.innerWidth > 480) {
    jQuery(fb_chat).attr("data-width", 640);
  }
</script>