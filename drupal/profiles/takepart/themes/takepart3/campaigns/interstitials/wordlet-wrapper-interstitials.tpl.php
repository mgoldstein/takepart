<div id="fb-root"></div>
<script>(function(d, s, id) {
  var js, fjs = d.getElementsByTagName(s)[0];
  if (d.getElementById(id)) return;
  js = d.createElement(s); js.id = id;
  js.src = "//connect.facebook.net/en_US/all.js#xfbml=1&appId=1395504993999657";
  fjs.parentNode.insertBefore(js, fjs);
}(document, 'script', 'facebook-jssdk'));</script>
<div id="page-wrapper" class="campaign">
  <?php print $header ?>

  <!-- start -->

  <main id="page" class="main">
    <?=$content?>
  </main>
      
  <!-- end -->

  <?php print $footer ?>
</div>