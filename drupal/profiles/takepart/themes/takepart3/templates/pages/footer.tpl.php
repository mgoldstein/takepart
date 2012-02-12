<div id="footer" class='clear'>

    <?php print render($page['footer']) ?>
    
    <?php if (!(is_null($takepart_topics_nav) || empty($takepart_topics_nav))): ?>
        <div id="footer-topic-links" class="footer-column-wrapper">
            <div class="column-title">Topics</div>
            <!--/column-->
            <?php print $takepart_topics_nav ?>
        </div>
    <?php endif; ?>

    <?php if (!(is_null($film_camp_nav) || empty($film_camp_nav))): ?>
        <div id="our-film-campaigns" class="footer-column-wrapper">
            <div class="column-title">film campaigns</div>
            <!--/column-->
            <?php print $film_camp_nav ?>
            
            <div id="footer-more-campaigns"><a href="/film-campaigns">More Film Campaigns</a></div>
        </div>
    <?php endif; ?>

    <?php if (!(is_null($friends_takepart_nav) || empty($friends_takepart_nav))): ?> 
        <!-- <div id="friends-of-takepart" class="footer-column-wrapper">
        <div class="column-title">friends of takepart</div>
        -->
            <?php // print $friends_takepart_nav; ?>
        <!-- </div> -->
    <?php endif; ?>

    <?php if (!(is_null($corporate_links_nav) || empty($corporate_links_nav))): ?>
        <div id="footer-set-links" class="footer-column-wrapper">
            <div class="column-title">About TakePart</div>
            <!--/column-->
            <?php print $corporate_links_nav; ?>
        </div>
    <?php endif; ?>

    <div id="footer-links-share" class="footer-column-wrapper">
        <div class="column-title">Connect</a></div>
        <ul id="bottom-follow">
            <li class="fb"><a href="http://www.facebook.com/takepart" target="_blank">facebook</a></li>
            <li class="twitter"><a href="http://www.twitter.com/takepart" target="_blank">twitter</a></li>
            <li class="youtube"><a href="http://www.youtube.com/takepart" target="_blank">youtube</a></li>
            <li class="rss"><a href="/rss">rss</a></li>
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