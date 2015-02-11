<footer id="site-footer">
  <div class="inner">
    <?php if ( ($nav = _smenu('menu-takepart-topics')) ): ?>
      <section id="site-topics">
        <h4><?=t('Topics') ?></h4>
        <?=$nav ?>
      </section>
    <?php endif ?>

    <?php if ( ($nav = _smenu('menu-takepart-film-campaigns')) ): ?>
      <section id="site-campaigns">
        <h4><?=t('Film Campaigns') ?></h4>
        <?=$nav ?>
        <p id="site-more-campaigns">
          <a href="/film-campaigns"><?=t('More Film Campaigns') ?></a>
        </p>
      </section>
    <?php endif ?>

    <?php if ( ($nav = _smenu('menu-takepart-links')) ): ?>
      <section id="site-takepart-links">
        <h4><?=t('About TakePart') ?></h4>
        <?=$nav ?>
      </section>
    <?php endif ?>

    <section id="site-connect">
      <h4><?=t('Connect') ?></h4>
      <ul>
        <li class="facebook"><a href="http://www.facebook.com/takepart">Facebook</a></li>
        <li class="twitter"><a href="http://www.twitter.com/takepart">Twitter</a></li>
        <li class="google"><a href="https://plus.google.com/113369936500827860065?prsrc=3">Google+</a></li>
        <li class="pinterest"><a href="http://pinterest.com/takepart/">Pinterest</a></li>
        <li class="youtube"><a href="http://www.youtube.com/takepart">YouTube</a></li>
        <li class="tumblr"><a href="http://takepart.tumblr.com/">Tumblr</a></li>

        <!-- li class="rss"><a href="/rss">RSS</a></li -->
      </ul>
    </section>
  </div>

  <section id="site-about">
    <p id="site-participant"><?=t('TakePart is the digital division of') ?> <a target="_blank" href="http://www.participantmedia.com/"><?=t('Participant Media') ?></a></p>
    <p id="site-copyright">&copy; 2008-<?=date('Y') ?> TakePart, LLC</p>
  </section>
</footer>