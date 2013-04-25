<div class="first-block" <?=wa('cta_image')?>>
    <div class="header-block cms">
        <h2><?=w('cta_header')?></h2>
        <h3><?=w('cta_subheader')?></h3>
        <div class="vote-desc">
            <?=w('vote_desc')?>
        </div>
    </div>
    <? if ( $w = w('cta_image') ): ?>
    <div class="prize-image">
        <img src="<?=$w->img_src?>" alt="<?=$w->single(false)?>">
    </div>
    <? endif ?>
</div>
<div class="second-block">
    <div class="vote" <?=wa('finalists')?>>
        <h3><?=w('vote_header')?></h3>
        
        <div class="finalists-menu">
        <?
        $finalists = wl('finalists', true);
        ?>
        <? foreach ( $finalists as $i => $w ): ?>
            <?if($i == 0):?>
            <div class="sect-one">
            <?endif?>
                <div class='finalist'>
                    <a href="<?=wu('intelchange_vote')?>#<?=$w->token?>">
                        <div class="portrait">
                            <img src="<?=$w->img_src?>" alt="<?=$w->single(false)?>">
                        </div>                    
                        <span class="name"><?=$w->single(false)?></span>
                    </a>
                </div>
            <?if($i == (($finalists->count() / 2) - 1)):?>
            </div>
            <div class="sect-two">
            <?endif?>
            <?if($i == ($finalists->count() - 1)):?>
            </div>
            <?endif?>
        <? endforeach ?>
        </div>
        
        <div class="finalist-content">
            <? foreach ( $finalists as $i => $w ): ?>
            <div id='<?=$w->token?>' class="finalist">
                <div class="video">
                    <iframe width="541" height="305" src="http://www.youtube.com/embed/<?=$w->video?>" frameborder="0" allowfullscreen></iframe>
                </div>
                <div class="details">
                    <h4 class="name"><?=$w->single(false)?></h4>
                    <div class="cms">
                        <div class='facts'><?=$w->multi_short(false)?></div>
                        <div class='blurb'><?=$w->multi(false)?></div>
                        <? $w2 = w('content_full_'.$w->token); ?>
                        <div class="full-text"<?=wa('content_full_'.$w->token)?>>
                            <?=$w2->multi(false)?>
                        </div>                    
                    </div>
                    <? if (w($w->token . '_vote_form')->vote_allowed): ?>
                    <p class="vote-btn important">
                        <a href="<?=wu('intelchange_vote')?>#vote_<?=$w->token?>"><?=wr(w('vote_finalist_button'), $w)?></a>
                    </p>
                    <? else: ?>
                    <div class="already-voted">
                        <p><?=wr(w('already_voted'), $w)?></p>
                    </div>
                    <? endif ?>
                    <p <?=wa('vote_finalist_button')?>>Edit Vote Button</p>
                    <p <?=wa('already_voted')?>>Edit Already Voted Text</p>
                    <div class="modal-wrapper">
                        <? if(!user_is_logged_in()): ?>
                        <div class="modal vote-register">
                            <? $w2 = w('fb_signup_modal') ?>
                            <h5 class='title'><?=$w2->single(false)?></h5>
                            <div class='cms modal-content'><?=$w2->multi(false)?></div>
                            <div class='fb-connect-wrapper'>
                                <?=_takepart_facebookapis_getfblogin("intelforchange/contest/vote#vote_".$w->token);?>
                            </div>
                        </div>
                        <? else: ?>
                        <div class="modal vote-confirm">
                            <div class="cms vote-form-wrapper">
                                <? $w2 = w('confirm_modal') ?>
                                <h5 class='title'><?=$w2->single(false)?></h5>
                                <div class='cms modal-content'>
                                    <?=wr($w2->multi(false), $w) ?>
                                </div>
                                <div class="cms vote-form-wrapper">
                                    <?=w($w->token . '_vote_form')->vote_allowed?>
                                </div>
                                <div class="cms footnote">
                                    <?=$w2->multi_short(false)?>
                                </div>
                                <span class='cancel'>Cancel</span>
                            </div>
                        </div>
                        <? endif ?>
                        <div class="modal vote-thanks">
                            <? $w2 = w('thank_you_modal') ?>
                            <h5 class='title'><?=$w2->single(false)?></h5>
                            <div class='cms modal-content'><?=wr($w2->multi(false), $w) ?></div>
                            <? $w2 = w('thank_you_add_this'); ?>
                            <div class="addThis"
                                data-message="<?=wr($w2->single(false), $w) ?>"
                                data-url="<?=wr($w2->href, $w) ?>">
                                <a class="addthis_button_facebook at300b" title="Facebook" href="#"><img src="/profiles/takepart/modules/takepart_addthis/images/ta_fb_share.png" alt="Share on Facebook"></a>
                                <a class="addthis_button_twitter at300b" title="Tweet" href="#"><img src="/profiles/takepart/modules/takepart_addthis/images/ta_twitter_share.png" alt="Share on Twitter"></a>
                                <a class="addthis_button_email at300b" title="Email" href="#"><img src="/profiles/takepart/modules/takepart_addthis/images/ta_email_share.png" alt="Share by Email"></a>
                            </div>
                        </div>
                        <div class="modal vote-error">
                            <? $w2 = w('error_modal') ?>
                            <h5 class='title'><?=$w2->single(false)?></h5>
                            <div class='cms modal-content'><?=$w2->multi(false)?></div>
                        </div>
                        <div class="modal vote-rejected">
                            <? $w2 = w('rejected_modal') ?>
                            <h5 class='title'><?=$w2->single(false)?></h5>
                            <div class='cms modal-content'><?=$w2->multi(false)?></div>
                        </div>
                    </div>
                    <? if ( wordlet_edit_mode() ): ?>
                        <h5>Modal Wordlets</h5>
                        <p <?=wa('fb_signup_modal')?>>Edit Registration Modal</p>
                        <p <?=wa('confirm_modal')?>>Edit Confirm Modal</p>
                        <p <?=wa($w->token . '_vote_form')?>>Edit Confirm Modal Vote Form</p>
                        <p <?=wa('thank_you_modal')?>>Edit Thank You Modal</p>
                        <p <?=wa('thank_you_add_this')?>>Edit Thank You Modal Add This Block</p>
                        <p <?=wa('rejected_modal')?>>Edit Rejected Modal</p>
                        <p <?=wa('error_modal')?>>Edit Error Modal</p>
                    <? endif ?>
                    <? $w2 = w('finalist_add_this'); ?>
                    <div class="addThis"
                        data-message="<?=wr($w2->single(false), $w)?>"
                        data-url="<?=wr($w2->href, $w)?>"
                        <?=wa('finalist_add_this')?>>
                        <a class="addthis_button_facebook at300b" title="Facebook" href="#"><img src="/profiles/takepart/modules/takepart_addthis/images/ta_fb_share.png" alt="Share on Facebook"></a>
                        <a class="addthis_button_twitter at300b" title="Tweet" href="#"><img src="/profiles/takepart/modules/takepart_addthis/images/ta_twitter_share.png" alt="Share on Twitter"></a>
                        <a class="addthis_button_email at300b" title="Email" href="#"><img src="/profiles/takepart/modules/takepart_addthis/images/ta_email_share.png" alt="Share by Email"></a>
                    </div>
                </div>
            </div>
            <? endforeach ?>
        </div>
    </div>
</div>