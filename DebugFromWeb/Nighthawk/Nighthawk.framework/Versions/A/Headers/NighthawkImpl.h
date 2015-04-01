//
//  Nighthawk.h
//  Nighthawk
//
//  Created by Denis Stadniczuk on 19/01/15.
//  Copyright (c) 2015 Clevertech. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface NighthawkImpl : NSObject

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
+(NighthawkImpl*)sharedInstance;

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
-(void)logMessage:(NSString*)message args:(va_list)args;

/**
 Send a log message with a tag
 @discussion they will only be sent to the server/console if the parameters are configured in NHConfiguration.h
 @param tag the tag
 @param message the log message
 */
-(void)logMessage:(NSString*)tag message:(NSString*)message args:(va_list)args;

/**
 Send an alert message
 @discussion there are special log messages that are logged to Slack. They will be always sent to the server, but depending on kNHLogToConsole they will be logged to console or not
 @param message the log message
 */
-(void)sendAlertMessage:(NSString*)message args:(va_list)args;

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
 * Implementations of these methods is therefore empty according to kNHProduction
 */


/**
 Sends a screenshot every n seconds. See NHConfiguartion.h
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
@property (nonatomic, readwrite, strong) NSString* sessionID;

/**
 If you want to query the database from the web UI, you have to set this to you managed object context
 */
@property (nonatomic, readwrite, strong) NSManagedObjectContext* managedObjectContext;

@end
