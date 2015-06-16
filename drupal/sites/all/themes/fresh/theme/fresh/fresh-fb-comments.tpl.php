<a class="comments-count"><span class="icon i-chat-bubble"></span> Show Comments (<fb:comments-count href="<?php print $variables['url']; ?>" >0</fb:comments-count>)</a>

<fb:comments class="fb_chat" data-numposts="1"  href="<?php print $variables['url']; ?>" class="fb_comments"></fb:comments>

<script type="text/javascript">
  var fb_chat = $(".fb_chat");
  if (window.innerWidth > 480) {
    $(fb_chat).attr("data-width", 640);
  }
</script>
