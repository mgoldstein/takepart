<div id="page-wrapper" class="campaign">
<?php print $header ?>
    <div class="smartgirls">
        <?=we("site_title")?>
        <?=we("subtitle")?>
        <div class="header-block">
            <span class="logo-intro">Presented by</span>
            <img src="/profiles/takepart/themes/takepart3/campaigns/intelchange/images/intel_logo.png" alt="Intel Logo" class="logo">
            <h1><?=w("title")?> <span class="subheader"><?=w("subtitle")?></span></h1>
        </div>
        <div class="first-block clearfix">
            <div class="main-info">
                <div class='vid-embed' data-previewSrc="/profiles/takepart/themes/takepart3/campaigns/intelchange/images/main_info.jpg" >
                    <iframe width="602" height="339" src="http://www.youtube.com/embed/kpPShxQJzG4?rel=0&showinfo=0&theme=light&showsearch=0&hd=1&cc_load_policy=1&enablejsapi=1" frameborder="0" allowfullscreen></iframe>
                </div>
            </div>
            <div class="intro">
                <?=w("intro_blurb")?>
                <div class="addThis">
                    <a class="addthis_button_facebook_like"></a>
                    <a class="addthis_button_tweet"></a>
                    <a class="addthis_button_email"></a>
                </div>
            </div>
        </div>
        <div class="second-block">
            <div class="form-desc">
                <h2><?=w("form_desc_title")?></h2>
                <div class="form-blurb">
                    <?=w("form_desc")?>
                </div>
            </div>
            <div class="form-wrapper">
                <div class="form-bg"></div>
                <div class="form-content">
                    <h3><?=w("form_title")?></h3>
                    <?=w("form_blurb")?>
                    <form>
                        <div class="field-wrapper email">
                            <label for="email">Email</label>
                            <input name="email" type="email" />
                        </div>
                        <div class="field-wrapper phone">
                            <label for="phone-areacode">Mobile Number <span class="optional">(Optional&#42;)</span></label>
                            <input name="phone-areacode" type="text">
                            <input name="phone-first" type="text">
                            <input name="phone-second" type="text">
                        </div>
                        <div class="field-wraper buttons">
                            <button class="submit">Submit</button>
                        </div>
                    </form>
                    <span class="optional-info">&#42;<?=w("form_optional_info")?></span>
                        <a class='terms-link' href='<?=w("terms_link")->href?>'><?=w("terms_link")->single?></a>
                    </div>
            </div>
        </div>
        <div class="footer-block"></div>
    </div>
<?php print $footer ?>
</div>