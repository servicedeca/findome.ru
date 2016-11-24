<div id="wrapper">

    <div class="container fin">
        <div class="col-xs-6 header-menu">
            <h1>
                <h1>Статьи</h1>
            </h1>
        </div>

    </div>
</div>

<div class="container-fluid container-fix all-complex-block">
    <div class="ap-header-layer-top h15">
    </div>

    <div class="container fin mb-50">
        <?php if (isset($articles)): ?>
            <?php foreach($articles as $nid => $article):?>
                <div class="col-xs-12 all-complex-item zero-padding">
                    <a href="/node/<?php print $nid; ?>" class="col-xs-4 ac-image zero-padding stock-details">
                        <?php print $article['image']?>
                    </a>
                    <div class="col-xs-8 border news-content">
                        <label></label>
                        <h2><?php print $article['title']; ?></h2>
                        <?php print $article['body']; ?>

                        <a class="slink_m stock-details" href="/node/<?php print $nid; ?>"> <?php print t('Читать далее'); ?></a>
                    </div>
                </div>
            <?php endforeach; ?>
        <?php endif; ?>
    </div>
</div>
