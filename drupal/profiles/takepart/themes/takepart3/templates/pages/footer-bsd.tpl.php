<div id="footer" class='clear'>
    <div id="footer-top-border" class="clear"></div>
    <?php print render($page['footer']) ?>
    
    <?php if (!(is_null($takepart_topics_nav) || empty($takepart_topics_nav))): ?>
        <div id="footer-topic-links" class="footer-column-wrapper">
            <div class="column-title">Topics</div>
            <!--/column-->
            <?php print $takepart_topics_nav; ?>
        </div>
    <?php endif; ?>

    <?php if (!(is_null($film_camp_nav) || empty($film_camp_nav))): ?>
        <div id="our-film-campaigns" class="footer-column-wrapper">
            <div class="column-title">film campaigns</div>
            <!--/column-->
            <?php print $film_camp_nav; ?>
            
            <div id="footer-more-campaigns">
                <?php print l("More Film Campaigns", "node/22525", array('attributes' => array('title' => 'TakePart logo'), 'absolute' => TRUE ) ); ?>
            </div>
        </div>
    <?php endif; ?>

    <?php if (!(is_null($corporate_links_nav) || empty($corporate_links_nav))): ?>
        <div id="footer-set-links" class="footer-column-wrapper">
            <div class="column-title">About TakePart</div>
            <!--/column-->
            <?php print $corporate_links_nav; ?>
        </div>
    <?php endif; ?>

    <div id="footer-links-share" class="footer-column-wrapper">
        <div class="column-title">Connect</div>
        <ul id="bottom-follow">
            <li class="fb"><a href="http://www.facebook.com/takepart" target="_blank" name="&lpos=footer">facebook</a></li>
            <li class="twitter"><a href="http://www.twitter.com/takepart" target="_blank" name="&lpos=footer">twitter</a></li>
            <li class="googleplus"><a href="https://plus.google.com/113369936500827860065?prsrc=3" name="&lpos=footer" rel="publisher" style="text-decoration:none;" target="_blank" title="google plus"><img src="https://ssl.gstatic.com/images/icons/gplus-32.png" alt="google plus" style="border:0;width:24px;height:24px;" /></a></li>
            <li class="youtube"><a href="http://www.youtube.com/takepart" target="_blank" name="&lpos=footer">youtube</a></li>
            <li class="rss"><?php print l("rss", "node/19814", array('attributes' => array('title' => 'RSS'), 'absolute' => TRUE ) ); ?></li>
        </ul>
        
        <div id="footer-about">
            <p>TakePart is the Social Action Network&trade; of <a target="_blank" href="http://www.participantmedia.com/">Participant Media</a></p>
            <div id="footer-legal">
                &copy; 2008-<?php echo date('Y'); ?>
                TakePart, LLC
            </div>
        </div>
    </div>

</div>
<div class="footer_rule"></div>