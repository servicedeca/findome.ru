<?php
/**
 * @file
 * realty_feature_image_style.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function realty_feature_image_style_image_default_styles() {
  $styles = array();

  // Exported image style: 500x526.
  $styles['500x526'] = array(
    'label' => '500x526',
    'effects' => array(
      3 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 500,
          'height' => 526,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      4 => array(
        'name' => 'canvasactions_definecanvas',
        'data' => array(
          'RGB' => array(
            'HEX' => '#282828',
          ),
          'under' => 1,
          'exact' => array(
            'width' => 500,
            'height' => 526,
            'xpos' => 'center',
            'ypos' => 'center',
          ),
          'relative' => array(
            'leftdiff' => '',
            'rightdiff' => '',
            'topdiff' => '',
            'bottomdiff' => '',
          ),
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: 667x450.
  $styles['667x450'] = array(
    'label' => '667x450',
    'effects' => array(
      5 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 667,
          'height' => 450,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      6 => array(
        'name' => 'canvasactions_definecanvas',
        'data' => array(
          'RGB' => array(
            'HEX' => '#4c4c4c',
          ),
          'under' => 1,
          'exact' => array(
            'width' => 667,
            'height' => 460,
            'xpos' => 'center',
            'ypos' => 'center',
          ),
          'relative' => array(
            'leftdiff' => '',
            'rightdiff' => '',
            'topdiff' => '',
            'bottomdiff' => '',
          ),
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: 690x630.
  $styles['690x630'] = array(
    'label' => '690x630',
    'effects' => array(
      7 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 690,
          'height' => 630,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      8 => array(
        'name' => 'canvasactions_definecanvas',
        'data' => array(
          'RGB' => array(
            'HEX' => '#4c4c4c',
          ),
          'under' => 1,
          'exact' => array(
            'width' => 690,
            'height' => 630,
            'xpos' => 'center',
            'ypos' => 'center',
          ),
          'relative' => array(
            'leftdiff' => '',
            'rightdiff' => '',
            'topdiff' => '',
            'bottomdiff' => '',
          ),
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: 960x600.
  $styles['960x600'] = array(
    'label' => '960x600',
    'effects' => array(
      9 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 960,
          'height' => 600,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      10 => array(
        'name' => 'canvasactions_definecanvas',
        'data' => array(
          'RGB' => array(
            'HEX' => '#4c4c4c',
          ),
          'under' => 1,
          'exact' => array(
            'width' => 960,
            'height' => 600,
            'xpos' => 'center',
            'ypos' => 'center',
          ),
          'relative' => array(
            'leftdiff' => '',
            'rightdiff' => '',
            'topdiff' => '',
            'bottomdiff' => '',
          ),
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: apartment_plan.
  $styles['apartment_plan'] = array(
    'label' => 'apartment_plan',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 700,
          'height' => 630,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      2 => array(
        'name' => 'canvasactions_definecanvas',
        'data' => array(
          'RGB' => array(
            'HEX' => '',
          ),
          'under' => 1,
          'exact' => array(
            'width' => 700,
            'height' => 630,
            'xpos' => 'center',
            'ypos' => 'center',
          ),
          'relative' => array(
            'leftdiff' => '',
            'rightdiff' => '',
            'topdiff' => '',
            'bottomdiff' => '',
          ),
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: apartment_plan_170x130.
  $styles['apartment_plan_170x130'] = array(
    'label' => 'apartment_plan_170x130',
    'effects' => array(
      5 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 170,
          'height' => 130,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      6 => array(
        'name' => 'canvasactions_definecanvas',
        'data' => array(
          'RGB' => array(
            'HEX' => '',
          ),
          'under' => 1,
          'exact' => array(
            'width' => 170,
            'height' => 130,
            'xpos' => 'center',
            'ypos' => 'center',
          ),
          'relative' => array(
            'leftdiff' => '',
            'rightdiff' => '',
            'topdiff' => '',
            'bottomdiff' => '',
          ),
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: apartment_plan_300x200.
  $styles['apartment_plan_300x200'] = array(
    'label' => 'apartment_plan_300x200',
    'effects' => array(
      3 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 300,
          'height' => 200,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      4 => array(
        'name' => 'canvasactions_definecanvas',
        'data' => array(
          'RGB' => array(
            'HEX' => '',
          ),
          'under' => 1,
          'exact' => array(
            'width' => 300,
            'height' => 200,
            'xpos' => 'center',
            'ypos' => 'center',
          ),
          'relative' => array(
            'leftdiff' => '',
            'rightdiff' => '',
            'topdiff' => '',
            'bottomdiff' => '',
          ),
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: apartment_plan_500x526.
  $styles['apartment_plan_500x526'] = array(
    'label' => 'apartment_plan_500x526',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 500,
          'height' => 526,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      2 => array(
        'name' => 'canvasactions_definecanvas',
        'data' => array(
          'RGB' => array(
            'HEX' => '',
          ),
          'under' => 1,
          'exact' => array(
            'width' => 500,
            'height' => 526,
            'xpos' => 'center',
            'ypos' => 'center',
          ),
          'relative' => array(
            'leftdiff' => '',
            'rightdiff' => '',
            'topdiff' => '',
            'bottomdiff' => '',
          ),
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: apartment_plan_750x500.
  $styles['apartment_plan_750x500'] = array(
    'label' => 'apartment_plan_750x500',
    'effects' => array(
      7 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 750,
          'height' => 500,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      8 => array(
        'name' => 'canvasactions_definecanvas',
        'data' => array(
          'RGB' => array(
            'HEX' => '#4c4c4c',
          ),
          'under' => 1,
          'exact' => array(
            'width' => 770,
            'height' => 520,
            'xpos' => 'center',
            'ypos' => 'center',
          ),
          'relative' => array(
            'leftdiff' => 10,
            'rightdiff' => 10,
            'topdiff' => 10,
            'bottomdiff' => 10,
          ),
        ),
        'weight' => 2,
      ),
      9 => array(
        'name' => 'canvasactions_file2canvas',
        'data' => array(
          'xpos' => 'center',
          'ypos' => 'center',
          'alpha' => 100,
          'path' => 'public://FD_watermark-07-07.png',
        ),
        'weight' => 3,
      ),
    ),
  );

  // Exported image style: apartment_plan_770x520.
  $styles['apartment_plan_770x520'] = array(
    'label' => 'apartment_plan_770x520',
    'effects' => array(
      10 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 750,
          'height' => 500,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      11 => array(
        'name' => 'canvasactions_definecanvas',
        'data' => array(
          'RGB' => array(
            'HEX' => '#4c4c4c',
          ),
          'under' => 1,
          'exact' => array(
            'width' => 770,
            'height' => 520,
            'xpos' => 'center',
            'ypos' => 'center',
          ),
          'relative' => array(
            'leftdiff' => 10,
            'rightdiff' => 10,
            'topdiff' => 10,
            'bottomdiff' => 10,
          ),
        ),
        'weight' => 2,
      ),
      12 => array(
        'name' => 'canvasactions_file2canvas',
        'data' => array(
          'xpos' => 'center',
          'ypos' => 'center',
          'alpha' => 100,
          'path' => 'public://FD_watermark-07-07.png',
        ),
        'weight' => 3,
      ),
    ),
  );

  // Exported image style: realty-1.
  $styles['realty-1'] = array(
    'label' => 'realty-1',
    'effects' => array(),
  );

  // Exported image style: realty_plan_floor.
  $styles['realty_plan_floor'] = array(
    'label' => 'realty_plan_floor',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 500,
          'height' => 433,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      2 => array(
        'name' => 'canvasactions_definecanvas',
        'data' => array(
          'RGB' => array(
            'HEX' => '#ffffff',
          ),
          'under' => 1,
          'exact' => array(
            'width' => 500,
            'height' => 433,
            'xpos' => 'center',
            'ypos' => 'center',
          ),
          'relative' => array(
            'leftdiff' => '',
            'rightdiff' => '',
            'topdiff' => '',
            'bottomdiff' => '',
          ),
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: realty_stock.
  $styles['realty_stock'] = array(
    'label' => 'realty_stock',
    'effects' => array(
      4 => array(
        'name' => 'image_resize',
        'data' => array(
          'width' => 297,
          'height' => 210,
        ),
        'weight' => 2,
      ),
    ),
  );

  return $styles;
}
