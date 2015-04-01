//
//  NighthawkImpl.h
//  Nighthawk
//
//  Created by Denis Stadniczuk on 17/02/15.
//  Copyright (c) 2015 Clevertech. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


#define kNHProduction 0

#if kNHProduction

#define NHDo(...)

#else

#define NHDo1(x) x
#define NHDo2(x...) x
#define NHDo3(x...) x
#define NHDo4(x...) x
#define NHDo5(x...) x
#define NHDo6(x...) x
#define NHDo7(x...) x
#define NHDo8(x...) x
#define NHDo9(x...) x
#define NHDo10(x...) x
#define NHDo11(x...) x
#define NHDo12(x...) x
#define NHDo13(x...) x
#define NHDo14(x...) x
#define NHDo15(x...) x
#define NHDo16(x...) x
#define NHDo17(x...) x
#define NHDo18(x...) x
#define NHDo19(x...) x
#define NHDo20(x...) x
#define NHDo21(x...) x
#define NHDo22(x...) x
#define NHDo23(x...) x
#define NHDo24(x...) x
#define NHDo25(x...) x
#define NHDo26(x...) x
#define NHDo27(x...) x
#define NHDo28(x...) x
#define NHDo29(x...) x

#define NHDoo(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,_17,_18,_19,_20,_21,_22,_23,_24,_25,_26,_27,_28,_29,NAME,...) NAME

/**
 NHDo is shorthand for doing an #if kNHProduction ... #endif
 Everything in NHDo is removed from production code
 Use: NHDo([[Nighthawk sharedInstance] sendScreenshot];)
 */
#define NHDo(...) NHDoo(__VA_ARGS__,NHDo29,NHDo28,NHDo27,NHDo26,NHDo25,NHDo24,NHDo23,NHDo22,NHDo21,NHDo20,NHDo19,NHDo18,NHDo17,NHDo16,NHDo15,NHDo14,NHDo13,NHDo12,NHDo11,NHDo10,NHDo9,NHDo8,NHDo7,NHDo6,NHDo5,NHDo4,NHDo3,NHDo2,NHDo1)(__VA_ARGS__)


#endif


@interface Nighthawk : NSObject

/**
 Use this instead of NHDo or preprocessor macros in swift projects
 */
+(BOOL)isProduction;


/**
 Make sure to call [Nighthawk initializeWithAPIKey:] on application start (applicationDidFinishLaunching)
 This will generate a new session UUID to identify the session
 @param key API key retrieved from the web interface
 */
+(void)initializeWithAPIKey:(NSString*)key;

/**
 Nighthawk singleton instance
 @returns the shared instance
 */
+(Nighthawk*)sharedInstance;

/**
 Send data to the server
 @discussion this can be anything you want to track
 @param type the type of the data
 @param data a dictionary of data you want to send
 */
-(void)sendDataOfType:(NSString*)type data:(NSDictionary*)data;

/**
 Send a message to the server
 @discussion this can be anything you want to track
 @param type the type of the message
 @param message a message you want to send
 */
-(void)sendMessageOfType:(NSString*)type message:(NSString*)message;

/**
 Sends a log message
 @discussion they will only be sent to the server/console if the parameters are configured in NHConfiguration.h
 @param message the log message
 */
-(void)logMessage:(NSString*)message, ...;

/**
 Send a log message with a tag
 @discussion they will only be sent to the server/console if the parameters are configured in NHConfiguration.h
 @param tag the tag
 @param message the log message
 */
-(void)logMessage:(NSString*)tag message:(NSString*)message, ...;

/**
 Send an alert message
 @discussion there are special log messages that are logged to Slack. They will be always sent to the server, but depending on kNHLogToConsole they will be logged to console or not
 @param message the log message
 */
-(void)sendAlertMessage:(NSString*)message, ...;

/**
 Sends a view inspection
 @param view that will be inspected and sent to the server
 */
-(void)sendViewInspection:(UIView*)view;

/**
 Sends a screen shot
 */
-(void)sendScreenshot;

/**
 Sends a screeb shot with a description
 @param text description that will be sent
 */
-(void)sendScreenshotWithDescription:(NSString*)text;


/**
 * Automatic screenshots should only be used in dev mode
 * Session recording uses private APIs, Apple will reject the app
 */


/**
 Sends a screenshot every n seconds. See NHConfiguration.h
 */
-(void)enableAutomaticScreenshots;

/**
 Disables sending a screenshot every n seconds
 */
-(void)disableAutomaticScreenshots;

/**
 Enables sending all touch events to the server
 */
-(void)enableSessionRecording;

/**
 Disables sending all touch events to the server
 */
-(void)disableSessionRecording;

/**
 Tells you if touches are currently recorded
 */
-(BOOL)isSessionRecordingEnabled;

/**
 The session UUID, unique for each session
 */
@property (nonatomic, readonly, strong) NSString* sessionID;

/**
 If you want to query the database from the web UI, you have to set this to you managed object context
 */
@property (nonatomic, readwrite, strong) NSManagedObjectContext* managedObjectContext;

/**
 *  An array of strings, for example @[@"tag1", @"tag2"]
 *  Only log messages with on of these tags (or without any tag) will be logged to the server
 */
@property (nonatomic, readwrite, strong) NSArray *serverLogTags;

@end
