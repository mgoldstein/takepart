<?php if ($is_multipage): ?>
<div id="page-wrapper" class="multipage-campaign">
<?php else: ?>
<div id="page-wrapper" class="campaign">
<?php endif; ?>

        <?php print $header ?>

        <link rel="stylesheet" href="/profiles/takepart/themes/takepart3/css/intel_change/intel_change.css">
        <div class="smartgirls">
            <div class="header-block">
                <img src="/profiles/takepart/themes/takepart3/images/intel_change/intel_logo.png" alt="Intel For Change Logo" class="logo">
                <h1>Smart Girls = Smart World</h1>
            </div>
            <div class="first-block clearfix">
                <img src="/profiles/takepart/themes/takepart3/images/intel_change/main_info.jpg" alt="77.6 million girls are currently not enrolled in either primary or secondary education" class="main-info">
                <div class="intro">
                    <p>Intel believes that education should be a fundamental right for everyone. In many parts of the world, girls and women are disproportionally denied access to education.</p>
                    <p>Join Intel to ensure that education is an opportunity for all.</p>
                    <div class="addThis">
                        <a class="addthis_button_facebook_like"></a> 
                        <a class="addthis_button_tweet"></a>
                    </div>
                </div>
            </div>
            <div class="second-block">
                <div class="form-desc">
                    <h2>Will you help make the change?</h2>
                    <p class='form-blurb'>Three people will be selected to become an Intel for Changemaker. Along with a film crew, each Changemaker will be sent to one of three countries to spend two weeks volunteering, making a real difference on the ground. A web series will be produced featuring each Changemaker and their experience abroad. The Changemakers will become a voice for girls’ education, raising awareness and funds for this issue.</p>
                </div>
                <div class="form-wrapper">
                    <h3>Excited? We are too.</h3>
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

<!--
        <?php if ($page['highlighted']): ?>
            <div id='highlighted'>
                <div class='clear limiter clearfix'>
                    <?php print render($page['highlighted']); ?>
                </div>
            </div>
        <?php endif; ?>

        <?php if ($page['full_width_top']): ?>
          <?php print render($page['full_width_top']); ?>
        <?php endif; ?>

        <div id='page' class='clear page clearfix <?php print $multipage_class; ?> <?php print render($node->type); ?>'>
            <div class='main-content'>
                <?php /* if ($title): ?><h1 class='page-title'><?php print $title ?></h1><?php endif; */ ?>
                <?php if (isset($primary_local_tasks)): ?><ul class='links clearfix'><?php print render($primary_local_tasks) ?></ul><?php endif; ?>
                <?php if (isset($secondary_local_tasks)): ?><ul class='links clearfix'><?php print render($secondary_local_tasks) ?></ul><?php endif; ?>
                <?php if ($action_links): ?><ul class='links clearfix'><?php print render($action_links); ?></ul><?php endif; ?>
                <?php if ($tabs): ?><div class="tabs"><?php print render($tabs); ?></div><?php endif; ?>

                <?php if ($page['help'] || ($show_messages && $messages)): ?>
                    <div id='console'>
                        <div class='limiter clearfix'>
                            <?php print render($page['help']); ?>
                            <?php if ($show_messages && $messages): print $messages;
                            endif; ?>
                        </div>
                    </div>
                <?php endif; ?>
<?php print render($page['content_top']); ?>

                <div id='content' class='clearfix'>
<?php print render($page['content']) ?>
                </div>

                <?php if ($page['sidebar_first']): ?>
                    <div id='left-rail' class='clearfix'><?php print render($page['sidebar_first']) ?></div>
                <?php endif; ?>

<?php print render($page['content_bottom']); ?>

            </div>

            <?php if ($page['sidebar_second']): ?>
                <div id='right-rail' class='clearfix'><?php print render($page['sidebar_second']) ?></div>
<?php endif; ?>

        </div>

        <?php if ($page['full_width_bottom']): ?>
          <?php print render($page['full_width_bottom']); ?>
        <?php endif; ?>
-->
<?php print $footer ?>

</div>