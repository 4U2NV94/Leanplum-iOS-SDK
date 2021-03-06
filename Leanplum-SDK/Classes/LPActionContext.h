//
//  Leanplum.h
//  Leanplum iOS SDK Version 2.0.6
//
//  Copyright (c) 2012 Leanplum, Inc. All rights reserved.
//
//  Licensed to the Apache Software Foundation (ASF) under one
//  or more contributor license agreements.  See the NOTICE file
//  distributed with this work for additional information
//  regarding copyright ownership.  The ASF licenses this file
//  to you under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//  http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing,
//  software distributed under the License is distributed on an
//  "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
//  KIND, either express or implied.  See the License for the
//  specific language governing permissions and limitations
//  under the License.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface LPActionContext : NSObject

- (NSString *)actionName;

- (NSString * _Nullable)stringNamed:(NSString *)name;
- (NSString * _Nullable)fileNamed:(NSString *)name;
- (NSNumber * _Nullable)numberNamed:(NSString *)name;
- (BOOL)boolNamed:(NSString *)name;
- (NSDictionary * _Nullable)dictionaryNamed:(NSString *)name;
- (NSArray * _Nullable)arrayNamed:(NSString *)name;
- (UIColor * _Nullable)colorNamed:(NSString *)name;
- (NSURL * _Nullable)htmlWithTemplateNamed:(NSString *)templateName;

/**
 * Runs the action given by the "name" key.
 */
- (void)runActionNamed:(NSString *)name;

/**
 * Runs and tracks an event for the action given by the "name" key.
 * This will track an event if no action is set.
 */
- (void)runTrackedActionNamed:(NSString *)name;

/**
 * Tracks an event in the context of the current message.
 */
- (void)track:(NSString *)event withValue:(double)value andParameters:(NSDictionary * _Nullable)params;

/**
 * Tracks an event in the conext of the current message, with any parent actions prepended to the
 * message event name.
 */
- (void)trackMessageEvent:(NSString *)event
                withValue:(double)value
                  andInfo:(NSString * _Nullable)info
            andParameters:(NSDictionary * _Nullable)params;

/**
 * Prevents the currently active message from appearing again in the future.
 */
- (void)muteFutureMessagesOfSameKind;

/**
 * Checks if the action context has any missing files that still need to be downloaded.
 */
- (BOOL)hasMissingFiles;

@end

NS_ASSUME_NONNULL_END
