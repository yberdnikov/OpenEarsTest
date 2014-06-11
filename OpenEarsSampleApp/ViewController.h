//  ViewController.h
//  OpenEarsSampleApp
//
//  ViewController.h demonstrates the use of the OpenEars framework. 

#import <UIKit/UIKit.h>
#import <Slt/Slt.h>

@class PocketsphinxController;
@class FliteController;

#import <OpenEars/OpenEarsEventsObserver.h> // We need to import this here in order to use the delegate.

@interface ViewController : UIViewController <OpenEarsEventsObserverDelegate>


// Example for reading out the input audio levels without locking the UI using an NSTimer

- (void) startDisplayingLevels;
- (void) stopDisplayingLevels;

// These three are the important OpenEars objects that this class demonstrates the use of.
@property (nonatomic, strong) Slt *slt;

@property (nonatomic, strong) OpenEarsEventsObserver *openEarsEventsObserver;
@property (nonatomic, strong) PocketsphinxController *pocketsphinxController;

@property (nonatomic, strong) IBOutlet UITextView *statusTextView;
@property (nonatomic, strong) IBOutlet UITextView *heardTextView;
@property (nonatomic, strong) IBOutlet UILabel *pocketsphinxDbLabel;
@property (nonatomic, strong) IBOutlet UILabel *fliteDbLabel;

@property (nonatomic, assign) int restartAttemptsDueToPermissionRequests;
@property (nonatomic, assign) BOOL startupFailedDueToLackOfPermissions;
// Things which help us show off the dynamic language features.
@property (nonatomic, copy) NSString *pathToFirstDynamicallyGeneratedLanguageModel;
@property (nonatomic, copy) NSString *pathToFirstDynamicallyGeneratedDictionary;

// Our NSTimer that will help us read and display the input and output levels without locking the UI
@property (nonatomic, strong) 	NSTimer *uiUpdateTimer;

@end

