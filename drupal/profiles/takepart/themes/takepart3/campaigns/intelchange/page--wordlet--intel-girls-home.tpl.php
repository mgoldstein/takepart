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
            <p>Give us your email and/or mobile number and we’ll keep you in the know.</p>
            <form>
                <div class="field-wrapper email">
                    <label for="email">Email</label>
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
            <span class="optional-info">*Message/data rates may apply. Text STOP to 77177 to unsubscribe and HELP for info. Max 5 msgs/month.</span>
        </div>
    </div>
    <div class="footer-block"></div>
</div>

<?php print $footer ?>
</div>