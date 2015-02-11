<?
  $form = $variables['element'];
  unset($form['which_award']['lifestyle']['#theme_wrappers']);
  unset($form['which_award']['pioneer']['#theme_wrappers']);
?>

<?= render($form['form_build_id']); ?>
<?= render($form['form_token']); ?>
<?= render($form['form_id']); ?>

<section class="about-you">
  <header>
    <h3><?= render($form['about_you_heading']); ?></h3>
    <p><?= render($form['about_you_description']); ?></p>
  </header>
  <div class="textfields">
    <fieldset class="row-odd">
      <?= render($form['first_name']); ?>
    </fieldset>

    <fieldset>
      <?= render($form['last_name']); ?>
    </fieldset>

    <fieldset class="row-odd">
      <?= render($form['email']); ?>
    </fieldset>

    <fieldset class="date month">
      <?= render($form['dob_month']); ?>
    </fieldset>

    <fieldset class="date year">
      <?= render($form['dob_year']); ?>
    </fieldset>

    <fieldset class="row-odd">
      <?= render($form['city']); ?>
    </fieldset>

    <fieldset>
      <?= render($form['state']); ?>
    </fieldset>
  </div>

  <h4><?= render($form['which_award_label']); ?></h4>
  <fieldset class="checks-radios">
    <?= render($form['which_award']['lifestyle']) ?>
    <label for="edit-which-award-lifestyle"><?= render($form['lifestyle_award_label']); ?></label>
    <?= render($form['lifestyle_award_description']); ?>
  </fieldset>

  <fieldset class="checks-radios">
    <?= render($form['which_award']['pioneer']) ?>
    <label for="edit-which-award-pioneer"><?= render($form['pioneer_award_label']); ?></label>
    <?= render($form['pioneer_award_description']); ?>

    <?php if ( isset($form['which_award']['#inline_error']) ): ?>
      <label class="error"><?= $form['which_award']['#inline_error'] ?></label>
    <?php endif ?>
  </fieldset>

</section>

<section class="your-video">
  <header>
    <h3><?= render($form['your_video_heading']); ?></h3>
    <p><?= render($form['your_video_description']); ?></p>
  </header>
  <div class="textfields">
    <fieldset>
      <?= render($form['video_link']); ?>
    </fieldset>
  </div>
</section>

<section class="submission">
  <header>
    <h3><?= render($form['submission_heading']); ?></h3>
    <p><?= render($form['submission_description']); ?></p>
  </header>
  <fieldset class="checks-radios">
    <?= render($form['newsletter_opt_in']); ?>
  </fieldset>
  <fieldset class="checks-radios">
    <?= render($form['contest_rules_opt_in']); ?>
  </fieldset>
  <?= render($form['terms_of_service']); ?>
  <?= render($form['submit']); ?>
</section>
