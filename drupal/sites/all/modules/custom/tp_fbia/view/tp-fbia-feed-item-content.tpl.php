<!doctype html>
<html lang="en" prefix="op: http://media.facebook.com/op#">
  <head>
    <meta charset="utf-8">
    <link rel="canonical" href="<?php print $url; ?>">
    <meta property="op:markup_version" content="v1.0">
    <meta property="fb:use_automatic_ad_placement" content="true">
    <meta property="fb:article_style" content="<?php print $type; ?>">
  </head>
  <body>
    <article>
      <header>

        <h1><?php print $title; ?></h1>
        <h2><?php print $subhead; ?></h2>

        <?php /* Main Image */ ?>
        <figure>
          <img src="<?php print $image_url; ?>" />
          <figcaption><?php print $image_caption; ?></figcaption>
        </figure>

        <?php /* Timestamps */ ?>
        <time class="op-published" dateTime="<?php print date('c', $pubDate); ?>"><?php print date('M d, Y', $pubDate); ?></time>
        <time class="op-modified" dateTime="<?php print date('c', $updatedDate); ?>"><?php print date('M d, Y, h:i A', $updatedDate); ?></time>

        <?php /* Authors */ ?>
        <?php foreach($authors as $author): ?>
          <address>
            <?php print $author; ?>
          </address>
        <?php endforeach; ?>

        <?php /* AD CODE */ ?>
        <?php print $ads; ?>

      </header>

      <?php print $body; ?>

      <?php /* TODO: uncomment when done
      <figure class="op-tracker">
          <iframe>
            <!-- ADOBE ANALYTICS EMBED -->
          </iframe>
      </figure>
      */ ?>

      <?php /* Google Analytics  */ ?>
      <?php /* TODO: uncomment when done
      <figure class="op-tracker">
        <iframe>
          <script>
          (function(i,s,o,g,r,a,m){i['GoogleAnalyticsObject']=r;i[r]=i[r]||function(){
          (i[r].q=i[r].q||[]).push(arguments)},i[r].l=1*new Date();a=s.createElement(o),
          m=s.getElementsByTagName(o)[0];a.async=1;a.src=g;m.parentNode.insertBefore(a,m)
          })(window,document,'script','//www.google-analytics.com/analytics.js','ga');
          ga('create', 'UA-95521-7', 'auto');
          ga('send', 'pageview');
          </script>
        </iframe>
      </figure>
      */ ?>

      <footer>

        <?php /* Related Sponsored Stories */ ?>
        <?php if(!$related_url || !$releated_title): ?>
          <ul class="op-related-articles">
            <li data-sponsored="true"><a href="<?php print $related_url; ?>?cmpid=tp-rss-fbinstant"><?php print $related_title; ?></a></li>
          </ul>
        <?php endif; ?>


        <small>&copy; <?php print date('Y'); ?> TakePart, LLC. All rights reserved.</small>

      </footer>
    </article>
  </body>
</html>
