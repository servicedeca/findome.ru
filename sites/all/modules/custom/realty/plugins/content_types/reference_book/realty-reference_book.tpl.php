<div class="container-fluid container-fix">
  <div class="col-xs-6 instruction-left">
  </div>
  <div class="col-xs-6 instruction-right">
  </div>
</div>

<div class="container fin">
  <div class="col-xs-12 instruction-body">
    <div class="col-xs-2 instruction-left-inner">
      <ul role="tablist">

        <?php foreach ($content['sections'] as $key => $section):?>

          <?php if (isset($content['active'])): ?>
            <?php if ($content['active'] == $key): ?>
              <li role="presentation" class="active">
                <a href="/#txt<?php print $key; ?>" role="tab" data-toggle="tab" aria-controls="home" aria-expanded="true">
                  <?php print $section['title']; ?>
                  <?php print $img_pointer; ?>
                </a>
              </li>
            <?php else: ?>
              <li role="presentation">
                <a href="/#txt<?php print $key; ?>" role="tab" data-toggle="tab" aria-controls="home" aria-expanded="true">
                  <?php print $section['title']; ?>
                  <?php print $img_pointer; ?>
                </a>
              </li>
            <?php endif; ?>
          <?php else: ?>
            <?php if ($activated != 'true'): $activated = 'true'; ?>
              <li role="presentation" class="active">
                <a href="/#txt<?php print $key; ?>" role="tab" data-toggle="tab" aria-controls="home" aria-expanded="true">
                  <?php print $section['title']; ?>
                  <?php print $img_pointer; ?>
                </a>
              </li>
            <?php else: ?>
              <li role="presentation">
                <a href="/#txt<?php print $key; ?>" role="tab" data-toggle="tab" aria-controls="home" aria-expanded="true">
                  <?php print $section['title']; ?>
                  <?php print $img_pointer; ?>
                </a>
              </li>
            <?php endif;?>
          <?php endif; ?>

        <?php endforeach; $activated = 'false'; ?>

      </ul>
    </div>
    <div class="col-xs-10 instruction-right-inner tab-content">

      <?php foreach ($content['sections'] as $key => $section): ?>

        <?php if (isset($content['active'])): ?>
          <?php if ($content['active'] == $key): ?>
            <div class="tab-pane fade active in col-xs-12 instruction-right-inner-text" role="tabpanel" aria-labelledby="home-tab" id="txt<?php print $key; ?>">
              <?php print $section['text']; ?>
            </div>
          <?php else: ?>
            <div class="tab-pane fade col-xs-12 instruction-right-inner-text" role="tabpanel" aria-labelledby="home-tab" id="txt<?php print $key; ?>">
              <?php print $section['text']; ?>
            </div>
          <?php endif; ?>
        <?php else: ?>
          <?php if ($activated != 'true'): $activated = 'true'; ?>
            <div class="tab-pane fade active in col-xs-12 instruction-right-inner-text" role="tabpanel" aria-labelledby="home-tab" id="txt<?php print $key; ?>">
              <?php print $section['text']; ?>
            </div>
          <?php else: ?>
            <div class="tab-pane fade col-xs-12 instruction-right-inner-text" role="tabpanel" aria-labelledby="home-tab" id="txt<?php print $key; ?>">
              <?php print $section['text']; ?>
            </div>
          <?php endif; ?>
        <?php endif;?>

      <?php endforeach; $activated = 'false'; ?>

    </div>
  </div>
</div>