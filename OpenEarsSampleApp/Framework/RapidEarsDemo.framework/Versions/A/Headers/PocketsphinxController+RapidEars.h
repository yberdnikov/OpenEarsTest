//
//  PocketsphinxController+RapidEars.h
//  RapidEars
//
//  Created by Halle Winkler on 5/3/12.
//  Copyright (c) 2012 Politepix. All rights reserved.
//

#import <OpenEars/PocketsphinxController.h>

/**
 @category  PocketsphinxController(RapidEars)
 @brief  A plugin which adds the ability to do live speech recognition to PocketsphinxController.
 
 ## Usage examples
 > Preparing to use the class:
 @htmlinclude PocketsphinxController+RapidEars_Preconditions.txt
 > What to add to your implementation:
 @htmlinclude PocketsphinxController+RapidEars_Implementation.txt
 @warning There can only be one PocketsphinxController+RapidEars instance in your app.
 */

/**\cond HIDDEN_SYMBOLS*/   

/**\endcond */   

@interface PocketsphinxController (RapidEars) {
}
/**Start the listening loop. You will call this instead of the old PocketsphinxController method*/
- (void) startRealtimeListeningWithLanguageModelAtPath:(NSString *)languageModelPath dictionaryAtPath:(NSString *)dictionaryPath acousticModelAtPath:(NSString *)acousticModelPath;

/**Turn logging on or off.*/
- (void) setRapidEarsToVerbose:(BOOL)verbose;

/**Scale from 1-20 where 1 is the least accurate and 20 is the most. This has an linear relationship with the CPU overhead. The best accuracy will still be less than that of Pocketsphinx in the stock OpenEars package and this only has a notable effect in cases where setFasterPartials is set to FALSE. Defaults to 20.*/
- (void) setRapidEarsAccuracy:(int)accuracy;

/**You can decide not to have the final hypothesis delivered if you are only interested in live hypotheses. This will save some CPU work.*/
- (void) setFinalizeHypothesis:(BOOL)finalizeHypothesis;

/** This will give you faster partial hypotheses at the expense of accuracy */
- (void) setFasterPartials:(BOOL)fasterPartials; 

/** This will give you faster final hypotheses at the expense of accuracy. Setting this causes setFasterPartials to also be set.*/
- (void) setFasterFinals:(BOOL)fasterPartials; 

/** Setting this to true will cause you to receive partial hypotheses even when they match the last one you received. This defaults to FALSE, so if you only want to receive new hypotheses you don't need to use this.*/
- (void) setReturnDuplicatePartials:(BOOL)duplicatePartials; 

/** Setting this to true will cause you to receive your hypotheses as separate words rather than a single NSString. This is a requirement for using OpenEarsEventsObserver delegate methods that contain timing or per-word scoring.*/
- (void) setReturnSegments:(BOOL)returnSegments; 

/** Setting this to true will cause you to receive segment hypotheses with timing attached. This is a requirement for using OpenEarsEventsObserver delegate methods that contain word timing information. It only works if you have setReturnSegments set to TRUE.*/
- (void) setReturnSegmentTimes:(BOOL)returnSegmentTimes; 

@end



