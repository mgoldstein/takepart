<? if ( wordlet_edit_mode() ): ?>
    <div class="wordlet_edit_mode">
        <p>
            Page Title: <?=w('title')?>
        </p>
        <? if ( ($wlinks = wordlet_configure_links()) ): ?>
            <p>Configure:
                <? foreach ( $wlinks as $wlink ): ?>
                    <span>
                        <?=$wlink?>
                    </span>
                <? endforeach ?>
            </p>
        <? endif ?>
    </div>
<? endif ?>

<div id="page-wrapper" class="campaign">
<?php print $header ?>

<div class="smartgirls">
    <div class="header-block">
        <img src="/profiles/takepart/themes/takepart3/campaigns/intelchange/images/intel_logo.png" alt="Intel For Change Logo" class="logo">
        <h1><?=w('title')?></h1>
    </div>
    <div class="first-block clearfix">
        <img src="/profiles/takepart/themes/takepart3/campaigns/intelchange/images/main_info.jpg" alt="77.6 million girls are currently not enrolled in either primary or secondary education" class="main-info">
        <div class="intro">
            <?=w('intro')?>
            <div class="addThis">
                <a class="addthis_button_facebook_like"></a> 
                <a class="addthis_button_tweet"></a>
            </div>
        </div>
    </div>
    <div class="second-block">
        <div class="form-desc">
            <h2><?=w('secondary_title')?></h2>
            <div class="form-blurb">
                <?=w('form-blurb')?>
            </div>
        </div>
        <div class="form-wrapper">
            <h3><?=w('form_title')?></h3>
            <p><?=w('form_subtitle')?></p>
            <form>
                <div class="field-wrapper email">
                    <label for="email"><?=w('email_label')?></label>
                    <input name="email" type="email" />
                </div>
                <div class="field-wrapper phone">
                    <label for="phone-areacode">Mobile Number <span class="optional">(Optional*)</span></label>
                    <input name="phone-areacode" type="text">
                    <input name="phone-first" type="text">
                    <input name="phone-second" type="text">
                </div>
                <div class="field-wraper buttons">
                    <button class="submit">Submit</button>
                </div>
                
            </form>
            <span class="optional-info"><?=w('form_disclaimer')?></span>
        </div>
    </div>
    <div class="footer-block"></div>
</div>

<?php print $footer ?>
</div>