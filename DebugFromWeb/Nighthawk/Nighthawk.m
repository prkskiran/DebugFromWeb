//
//  Nighthawk+Private.m
//  Nighthawk
//
//  Created by Denis Stadniczuk on 17/02/15.
//  Copyright (c) 2015 Clevertech. All rights reserved.
//

#import "Nighthawk.h"
#import <Nighthawk/NighthawkImpl.h>

@interface Nighthawk ()

@end

Nighthawk *NHsharedInstance = nil;

@implementation Nighthawk

+(BOOL)isProduction
{
    return kNHProduction;
}

+(void)initializeWithAPIKey:(NSString*)key
{
#if !kNHProduction
    if (NHsharedInstance == nil) {
        NHsharedInstance = [[Nighthawk alloc] init];
        [NighthawkImpl initializeWithAPIKey:key];
    }
#endif
}

+(Nighthawk*)sharedInstance
{
    return NHsharedInstance;
}

-(void)sendDataOfType:(NSString*)type data:(NSDictionary*)data
{
    NHDo([[NighthawkImpl sharedInstance] sendDataOfType:type data:data];)
}

-(void)sendMessageOfType:(NSString*)type message:(NSString*)message
{
    NHDo([[NighthawkImpl sharedInstance] sendMessageOfType:type message:message];)
}

-(void)logMessage:(NSString*)message, ...
{
    NHDo(
        va_list args;
        va_start(args, message);
        [[NighthawkImpl sharedInstance] logMessage:message args:args];
     )
}

-(void)logMessage:(NSString*)tag message:(NSString*)message, ...
{
    NHDo(
        va_list args;
        va_start(args, message);
        [[NighthawkImpl sharedInstance] logMessage:tag message:message args:args];
     )
}

-(void)sendAlertMessage:(NSString*)message, ...
{
    NHDo(
        va_list args;
        va_start(args, message);
         [[NighthawkImpl sharedInstance] sendAlertMessage:message args:args];
     )
}

-(void)sendViewInspection:(UIView*)view
{
    NHDo([[NighthawkImpl sharedInstance] sendViewInspection:view];)
}

-(void)sendScreenshot
{
    NHDo([[NighthawkImpl sharedInstance] sendScreenshot];)
}

-(void)sendScreenshotWithDescription:(NSString*)text
{
    NHDo([[NighthawkImpl sharedInstance] sendScreenshotWithDescription:text];)
}

-(void)enableAutomaticScreenshots
{
    NHDo([[NighthawkImpl sharedInstance] enableAutomaticScreenshots];)
}

-(void)disableAutomaticScreenshots
{
    NHDo([[NighthawkImpl sharedInstance] disableAutomaticScreenshots];)
}

-(void)enableSessionRecording
{
    NHDo([[NighthawkImpl sharedInstance] enableSessionRecording];)
}

-(void)disableSessionRecording
{
    NHDo([[NighthawkImpl sharedInstance] disableSessionRecording];)
}

-(BOOL)isSessionRecordingEnabled
{
#if !kNHProduction
    return [[NighthawkImpl sharedInstance] isSessionRecordingEnabled];
#else
    return NO;
#endif
}

-(NSString *)sessionID
{
#if !kNHProduction
    return [[NighthawkImpl sharedInstance] sessionID];
#else
    return nil;
#endif
}

-(void)setManagedObjectContext:(NSManagedObjectContext *)managedObjectContext
{
    NHDo([[NighthawkImpl sharedInstance] setManagedObjectContext:managedObjectContext];)
}

-(NSManagedObjectContext *)managedObjectContext
{
#if !kNHProduction
    return [[NighthawkImpl sharedInstance] managedObjectContext];
#else
    return nil;
#endif
}

@end
