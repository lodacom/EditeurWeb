#include "CSSData.h"

QRegExp CSSData::fileExtensionRegex("*.html *.htm");
QRegExp CSSData::keywordRegex("\\banimation\\b|\\banimation-delay\\b|\\banimation-direction\\b|\\banimation-duration\\b|\\banimation-fill-mode\\b|\\banimation-iteration-count\\b|\\banimation-name\\b|\\banimation-play-state\\b|\\banimation-timing-function\\b|\\bauto\\b|\\bbackface-visibility\\b|\\bbackground\\b|\\bbackground-attachment\\b|\\bbackground-clip\\b|\\bbackground-color\\b|\\bbackground-image\\b|\\bbackground-origin\\b|\\bbackground-position\\b|\\bbackground-repeat\\b|\\bbackground-size\\b|\\bborder\\b|\\bborder-bottom\\b|\\bborder-bottom-color\\b|\\bborder-bottom-right-radius\\b|\\bborder-bottom-left-radius\\b|\\bborder-bottom-style\\b|\\bborder-bottom-width\\b|\\bborder-collapse\\b|\\bborder-color\\b|\\bborder-image\\b|\\bborder-image-outset\\b|\\bborder-image-repeat\\b|\\bborder-image-slice\\b|\\bborder-image-source\\b|\\bborder-image-width\\b|\\bborder-left\\b|\\bborder-left-color\\b|\\bborder-left-style\\b|\\bborder-left-width\\b|\\bborder-radius\\b|\\bborder-right\\b|\\bborder-right-color\\b|\\bborder-right-style\\b|\\bborder-right-width\\b|\\bborder-spacing\\b|\\bborder-style\\b|\\bborder-top\\b|\\bborder-top-color\\b|\\bborder-top-left-radius\\b|\\bborder-top-right-radius\\b|\\bborder-top-style\\b|\\bborder-top-width\\b|\\bborder-width\\b|\\bbottom\\b|\\bbox-decoration-break\\b|\\bbox-shadow\\b|\\bbox-sizing\\b|\\bbreak-after\\b|\\bbreak-before\\b|\\bbreak-inside\\b|\\bcaption-side\\b|\\b@charset\\b|\\bclear\\b|\\bclip\\b|\\bclip-path\\b|\\bcolor\\b|\\bcolumns\\b|\\bcolumn-count\\b|\\bcolumn-fill\\b|\\bcolumn-gap\\b|\\bcolumn-rule\\b|\\bcolumn-rule-color\\b|\\bcolumn-rule-style\\b|\\bcolumn-rule-width\\b|\\bcolumn-span\\b|\\bcolumn-width\\b|\\bcontent\\b|\\bcounter-increment\\b|\\bcounter-reset\\b|\\bcursor\\b|\\bdirection\\b|\\bdisplay\\b|\\b@document\\b|\\bempty-cells\\b|\\bfloat\\b|\\bfont\\b|\\b@font-face\\b|\\bfont-family\\b|\\bfont-feature-settings\\b|\\bfont-kerning\\b|\\bfont-language-override\\b|\\bfont-size\\b|\\bfont-size-adjust\\b|\\bfont-stretch\\b|\\bfont-style\\b|\\bfont-variant\\b|\\bfont-variant-ligatures\\b|\\bfont-weight\\b|\\bheight\\b|\\bhyphens\\b|icon\\b|\\bimg\\b|\\bimage-rendering\\b|\\bimage-resolution\\b|\\bimage-orientation\\b|\\bime-mode\\b|\\b@import\\b|\\binherit\\b|\\binitial\\b|\\b@keyframes\\b|\\bleft\\b|\\bletter-spacing\\b|\\bline-height\\b|\\blist-style\\b|\\blist-style-image\\b|\\blist-style-position\\b|\\blist-style-type\\b|\\bmargin\\b|\\bmargin-bottom\\b|\\bmargin-left\\b|\\bmargin-right\\b|\\bmargin-top\\b|\\bmarker-offset\\b|\\bmarks\\b|\\bmask\\b|\\bmax-height\\b|\\bmax-width\\b|\\b@media\\b|\\bmin-height\\b|\\bmin-width\\b|\\b@namespace\\b|\\bnav-down\\b|\\bnav-index\\b|\\bnav-left\\b|\\bnav-right\\b|\\bnav-up\\b|\\bnone\\b|\\bnormal\\b|\\bobject-fit\\b|\\bobject-position\\b|\\bopacity\\b|\\borphans\\b|\\boutline\\b|\\boutline-color\\b|\\boutline-offset\\b|\\boutline-style\\b|\\boutline-width\\b|\\boverflow\\b|\\boverflow-x\\b|\\boverflow-y\\b|\\bpadding\\b|\\bpadding-bottom\\b|\\bpadding-left\\b|\\bpadding-right\\b|\\bpadding-top\\b|\\b@page\\b|\\bpage-break-after\\b|\\bpage-break-before\\b|\\bpage-break-inside\\b|\\bperspective\\b|\\bperspective-origin\\b|\\bpointer-events\\b|\\bposition\\b|\\bquotes\\b|\\bresize\\b|\\bright\\b|\\btable-layout\\b|\\btab-size\\b|\\btext-align\\b|\\btext-align-last\\b|\\btext-decoration\\b|\\btext-decoration-color\\b|\\btext-decoration-line\\b|\\btext-decoration-style\\b|\\btext-indent\\b|\\btext-overflow\\b|\\btext-rendering\\b|\\btext-shadow\\b|\\btext-transform\\b|\\btop\\b|\\btransform\\b|\\btransform-origin\\b|\\btransform-style\\b|\\btransition\\b|\\btransition-delay\\b|\\btransition-duration\\b|\\btransition-property\\b|\\btransition-timing-function\\b|\\bunicode-bidi\\b|\\bvertical-align\\b|\\b@viewport\\b|\\bvisibility\\b|\\bwhite-space\\b|\\bwidows\\b|\\bwidth\\b|\\bword-spacing\\b|\\bword-wrap\\b|\\bz-index\\b");
QRegExp CSSData::subclassRegex("\\b:active\\b|\\b::after\\b|\\b:after\\b|\\b::before\\b|\\b:before\\b|\\b:checked\\b|\\b:default\\b|\\b:disabled\\b|\\b:empty\\b|\\b:enabled\\b|\\b:first\\b|\\b:first-child\\b|\\b::first-letter\\b|\\b:first-letter\\b|\\b::first-line \\b|\\b:first-line\\b|\\b:first-of-type\\b|\\b:focus\\b|\\b:hover\\b|\\b:visited\\b|\\b:invalid\\b|\\b:indeterminate\\b|\\b:in-range\\b");
QRegExp CSSData::idRegex("#[$a-zA-Z_][a-zA-Z0-9_]*");
QRegExp CSSData::idclassRegex("\\.[$a-zA-Z_][a-zA-Z0-9_]*");
QRegExp CSSData::numberRegex("[0-9][0-9]*|[0-9][0-9]*\\.[0-9]+");
QRegExp CSSData::quotationRegex("\".*\"|\'.*\'");
QRegExp CSSData::multilineCommentStartRegex("/\\*");
QRegExp CSSData::multilineCommentEndRegex("\\*/");