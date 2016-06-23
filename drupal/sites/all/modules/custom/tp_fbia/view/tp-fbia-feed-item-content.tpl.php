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
        <?php /* Kicker */ ?>
        <?php if ($type == 'feature'): ?>

          <h3 class="op-kicker">
            TakePart #longform
          </h3>
        <?php endif; ?>

        <h1><?php print $title; ?></h1>
        <h2><?php print $subhead; ?></h2>

        <?php /* Main Image */ ?>

        <figure>
          <img src="<?php print $image_url; ?>" />
          <?php if (!empty($image_caption)): ?>
            <figcaption><?php print $image_caption; ?></figcaption>
          <?php endif; ?>
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

      <?php /* Adobe Analytics */ ?>

      <figure class="op-tracker">
          <iframe>
            <?php print $adobe_analytics; ?>
          </iframe>
      </figure>

      <?php /* Google Analytics */ ?>

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

     <?php /* PubExchange Tracking */ ?>

      <figure class="op-tracker">
        <iframe>
        <script>(function(l,d) {
          if (l.search.length){
            var m, u = {}, s = /([^&=]+)=?([^&]*)/g, q = l.search.substring(1);
            while (m = s.exec(q)) u[m[1]] = m[2];
              if (("pefbs" in u) && ("pefba" in u) && ("pefbt" in u)) {
                var pe = d.createElement("script"); pe.type = "text/javascript"; pe.async = true;
                pe.src = "http://traffic.pubexchange.com/click/" + u.pefbt + "/" + u.pefbs + "/" + u.pefba;
                var t = d.getElementsByTagName("script")[0]; t.parentNode.insertBefore(pe, t);
              }
            }
        }(window.location, document));</script>
        </iframe>
      </figure>
      <?php /* comScore Tracking */ ?>

      <figure class="op-tracker">
        <iframe>
          <script>
            var _comscore = _comscore || [];
            _comscore.push({ c1: "2", c2: "14223123", c3: "", c4: "<?php print $url; ?>", c5: "", c6: "", c15: "" });
            (function() {
              var s = document.createElement("script"), el = document.getElementsByTagName("script")[0]; s.async = true;
              s.src = (document.location.protocol == "https:" ? "https://sb" : "http://b") + ".scorecardresearch.com/beacon.js";
              el.parentNode.insertBefore(s, el);
            })();
          </script>
          <noscript>
            <img src="http://b.scorecardresearch.com/p?c1=2&c2=14223123&c3=&c4=<?php print $url; ?>&c5=&c6=&c15=&cv=2..0&cj=1" />
          </noscript>
        </iframe>
      </figure>

      <?php /* keywee tracking */ ?>
      <figure class="op-tracker">
        <iframe>
          <script src="//dc8xl0ndzn2cb.cloudfront.net/js/takepart/v0/keywee.min.js" type="text/javascript" async></script>
        </iframe>
      </figure>

      <?php /* End of Analytics */ ?>

      <footer>

        <?php /* Related Sponsored Stories */ ?>
        <?php if(!$related_url || !$releated_title): ?>
          <ul class="op-related-articles">
            <li data-sponsored="true"><a href="<?php print $related_url; ?>?cmpid=tp-rss-fbinstant"><?php print $related_title; ?></a></li>
          </ul>
        <?php endif; ?>


        <small>TakePart is the digital news magazine from Participant Media, the company behind acclaimed films Spotlight, CITIZENFOUR and An Inconvenient Truth. &copy; <?php print date('Y'); ?> TakePart, LLC. All rights reserved.</small>

      </footer>
    </article>
  </body>
</html>
