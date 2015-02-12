<div class="column">
    <div class="inner">
        <div class="cms">
            <?=w('body')?>
        </div>
    </div>
</div>

<div class="social-buttons">
    <div class="addthis_toolbox addthis_default_style addthis_32x32_style thank-you-addthis">
        <h3><?=w('share')?></h3>
        <a class="tpsocial-link tpsocial-facebook social-icon at300b" title="Facebook" href="#"><span class=" at300bs at15nc at15t_facebook"><span class="at_a11y">Share on facebook</span></span></a>
        <a class="addthis_button_twitter social-icon at300b" title="Tweet" addthis:url="http://bit.ly/WJIyQ3" href="#" <?=wa('twitter_text')?>><span class=" at300bs at15nc at15t_twitter"><span class="at_a11y">Share on twitter</span></span></a>
        <script>
        var addthis_share = {
            templates : {
                twitter : "<?=htmlspecialchars(w('twitter_text')->single(false))?>"
            }
        };
        </script>
        <!-- <a class="addthis_button_google_plusone" g:plusone:size="standard" g:plusone:annotation="none" title="Share on Google+1"></a> -->
        <a class="addthis_button_email at300b" target="_blank" title="Email" href="#" addthis:image="<?=w('fb_image')?>"><span class=" at300bs at15nc at15t_email"><span class="at_a11y">Share on email</span></span></a>
    </div>
</div>

<div class="snap-grid" <?=wa('snap_slides')?>>
    <div class="tile">
        <img src="/profiles/takepart/themes/takepart3/campaigns/patt/images/snap/tile-static-snap-logo.jpg" alt="Image">
    </div>

    <?php foreach ( wl('snap_slides') as $s ): ?>
        <div class="tile <?=$s->href?'link':''?> <?=$s->img_src?'person':''?> <?=(!$s->href && !$s->img_src)?'fact':''?>" data-token="<?=$s->token?>">
            <?php if ( $s->href ): // Outside link ?>
                <a href="<?=$s->href?>">
                    <img src="<?=$s->thumb_src?>"/>
                </a>
            <?php elseif ( !$s->href && !$s->img_src ): // Fact ?>
                <a href="?slide=<?=$s->token?>">
                    <h1 class="tile-header"><?=w('myth')?></h1>
                    <p><?=$s->single?></p>
                    <div class="veil">
                        <div class="veil_content">
                            <?=$s->multi_short(false)?>
                        </div>
                    </div>
                </a>
                <div class="modal-left">
                    <div class="fact">
                        <h1><?=w('myth')?></h1>
                        <p class="myth-fact"><?=$s->single?></p>
                    </div>
                </div>
                <div class="modal-right">
                    <div class="modal-content fact">
                        <div class="modal-header">
                            <h1 class="fact"><?=w('fact')?></h1>
                        </div>
                        <div class="description">
                            <?=$s->multi?>
                        </div>
                    </div>
                </div>
            <?php elseif( !$s->single(false) ): // Take your place graphic ?>
                <a href="?slide=<?=$s->token?>">
                    <img src="<?=$s->thumb_src?>"/>
                </a>
                <div class="modal-left">
                    <img src="<?=$s->img_src?>" alt="Take your place">
                </div>
                <div class="modal-right">
                    <div class="modal-content">
                        <div class="description take-your-place">
                            <?=$s->multi?>
                        </div>
                    </div>
                </div>
            <?php elseif ( $n = explode('|', $s->single(false)) ): // Person ?>
                <a href="?slide=<?=$s->token?>">
                    <img src="<?=$s->thumb_src?>"/>
                    <div class="veil">
                        <div class="veil_content">
                            <?=$s->multi_short(false)?>
                        </div>
                    </div>
                </a>
                <div class="modal-left">
                    <img src="<?=$s->img_src?>" alt="<?=$n[0]?>">
                </div>
                <div class="modal-right">
                    <div class="modal-content">
                        <div class="modal-header">
                            <h1><?=$n[0]?></h1><br/>
                            <h2><?=$n[1]?></h2><br/>
                            <h3><?=$n[2]?></h3>
                        </div>
                        <div class="description">
                            <?=$s->multi?>
                        </div>
                    </div>
                </div>
            <?php endif ?>
        </div>
    <?php endforeach ?>

</div>

<div id="grid-overlay">
    <div id="grid-modal" class="modal wrapper">
        <div class="close-btn"><img src="/profiles/takepart/themes/takepart3/campaigns/patt/images/snap/close-btn.jpg" alt="Close"></div>
        <div class="modal-left">
            
        </div>
        <div class="modal-right">
            <div class="modal-content">
                <div class="modal-header"></div>
                <div class="description"></div>
            </div>
        </div>
        <footer>
            <div class="modal-nav">
                <div id="nav-left" class="nav-button"><img src="/profiles/takepart/themes/takepart3/campaigns/patt/images/snap/nav-arrow-left.jpg" alt="Left"></div>
                <div id="nav-right" class="nav-button"><img src="/profiles/takepart/themes/takepart3/campaigns/patt/images/snap/nav-arrow-right.jpg" alt="right"></div>
            </div>
            <div id="social-buttons">
                <div class="addthis_toolbox addthis_toolbox_modal addthis_default_style addthis_32x32_style thank-you-addthis">
                  <a class="tpsocial-link tpsocial-facebook social-icon at300b" title="Facebook" href="#"><span class=" at300bs at15nc at15t_facebook"><span class="at_a11y">Share on facebook</span></span></a>
                  <a class="addthis_button_twitter social-icon at300b" title="Tweet" href="#"><span class=" at300bs at15nc at15t_twitter"><span class="at_a11y">Share on twitter</span></span></a>
                  <!-- <a class="addthis_button_google_plusone" g:plusone:size="standard" g:plusone:annotation="none" title="Share on Google+1"></a> -->
                  <a class="addthis_button_email at300b" target="_blank" title="Email" href="#"><span class=" at300bs at15nc at15t_email"><span class="at_a11y">Share on email</span></span></a>
                <div class="atclear"></div></div>
            </div>
        </footer>
    </div>
</div>
