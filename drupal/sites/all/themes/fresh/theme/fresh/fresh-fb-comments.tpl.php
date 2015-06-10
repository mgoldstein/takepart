<a class="comments-count" name="article-comments"><span class="icon i-chat-bubble"></span> Show Comments (<fb:comments-count href="<?php print $variables['url']; ?>" >0</fb:comments-count>)</a>

<fb:comments id="fb_chat" data-numposts="1"  href="<?php print $variables['url']; ?>" class="fb_comments"></fb:comments>

<script type="text/javascript">
  var fb_chat = document.getElementById('fb_chat');
  if (window.innerWidth > 480) {
    fb_chat.setAttribute("data-width", 640);
  }
  else {
    fb_chat.setAttribute("data-width", 320);
  }
</script>
