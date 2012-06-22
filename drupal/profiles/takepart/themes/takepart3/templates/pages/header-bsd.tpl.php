<div id="header-wrapper" class='clearfix regular-content'>
    <div id="join-login-top">
        <div class="login-fb clearfix">
            <?php print $user_nav; ?>       
        </div> 
    </div><!--/join-login-top-->
    <div class="logo-wrapper">
        <div id="logo"><?php print l("", "<front>", array('attributes' => array('title' => 'TakePart logo'), 'absolute' => TRUE)) ?></div>
        <div class="header-right">
            <div class="clear clearfix" id="nav-wrap">
                <div id="block-menu-block-1">
                    <?php print $top_nav; ?>
                </div>
            </div>
            <div id="hot-topics-nav">
                <?php print $hottopic_nav; ?>
            </div><!--/hot topics nav-->
            <?php print $follow_us_links; ?><!--/top follow-->
            <div id="top-search">
                <div class="tpform-item">
                    <form accept-charset="UTF-8" id="search-api-page-search-form-2" method="post" action="<?php print 'http://' . $_SERVER['HTTP_HOST']; ?>/">
                        <div>
                            <div class="form-item form-type-textfield form-item-keys-2">
                                <input type="text" class="form-text" maxlength="128" size="15" value="Search TakePart" name="keys_2" id="edit-keys-2" onfocus="if(this.value=='Search TakePart'){this.value=''};" />
                            </div>
                            <input type="hidden" value="2" name="id" />
                            <input type="submit" value="Search" name="op" id="edit-submit-2" class="tpform-submit form-submit" />
                            <input type="hidden" value="form-PwxcEln5_lbB9yxzLA10M9fgZv6QmDEQ6EIgLX8QgIE" name="form_build_id" />
                            <input type="hidden" value="sa4R066PFlBYTh3FGKg2tFJ6b12RiFXAQ6HjP91OwfI" name="form_token" />
                            <input type="hidden" value="search_api_page_search_form_2" name="form_id" />
                        </div>
                    </form>
                </div>
            </div><!--/top search-->
        </div>
    </div>
</div>