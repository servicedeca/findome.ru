<div class="container-fluid container-fix">
  <div class="zero-padding fotorama" data-width="100%"  data-loop="true" data-clicktransition="dissolve" data-arrows="true" data-click="false" data-swipe="false" data-nav="false">
    <?php foreach ($slides as $slide): ?>
      <div data-img="<?php print $slide['image']; ?>">
        <div class="<?php print $slide['class']; ?>">
          <h1><?php print $slide['title']; ?></h1>
          <p><?php print $slide['text']; ?></p>
        </div>
      </div>
    <?php endforeach; ?>
  </div>
</div>