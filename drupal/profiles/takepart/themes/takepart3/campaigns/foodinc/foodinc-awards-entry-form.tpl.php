<? $form = $variables['element']; ?>

<?= render($form['form_build_id']); ?>
<?= render($form['form_token']); ?>
<?= render($form['form_id']); ?>

<section>
  <header>
    <h3><?= render($form['about_you_heading']); ?></h3>
    <p><?= render($form['about_you_description']); ?></p>
  </header>
  <fieldset class="column2">
    <?= render($form['first_name']); ?>
  </fieldset>

  <fieldset class="column2">
    <?= render($form['last_name']); ?>
  </fieldset>

  <fieldset class="column2">
    <?= render($form['email']); ?>
  </fieldset>

  <fieldset>
    <?= render($form['dob_month']); ?>
    <?= render($form['dob_year']); ?>
  </fieldset>

  <fieldset class="column2">
    <?= render($form['city']); ?>
  </fieldset>

  <fieldset class="column2">
    <?= render($form['state']); ?>
  </fieldset>

  <fieldset>
    <?= render($form['which_award_label']); ?>
    <?= render($form['lifestyle_award']); ?>
    <?= render($form['lifestyle_award_description']); ?>
    <?= render($form['pioneer_award']); ?>
    <?= render($form['pioneer_award_description']); ?>
  </fieldset>
</section>

<section>
  <header>
    <?= render($form['your_video_heading']); ?>
    <?= render($form['your_video_description']); ?>
  </header>
  <?= render($form['video_link']); ?>
</section>

<section>
  <?= render($form['submission_heading']); ?>
  <?= render($form['submission_description']); ?>
  <?= render($form['newsletter_opt_in']); ?>
  <?= render($form['contest_rules_opt_in']); ?>
  <?= render($form['terms_of_service']); ?>
  <?= render($form['submit']); ?>
</section>