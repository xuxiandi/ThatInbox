//
//  MCOIMAPNamespace.h
//  mailcore2
//
//  Created by DINH Viêt Hoà on 3/23/13.
//  Copyright (c) 2013 MailCore. All rights reserved.
//

#ifndef __MAILCORE_MCOIMAPNAMESPACE_H_

#define __MAILCORE_MCOIMAPNAMESPACE_H_

/** Represents an IMAP namespace */

#import <Foundation/Foundation.h>

@class MCOIMAPNamespace;

@interface MCOIMAPNamespace : NSObject <NSCopying>

/**
 Returns a simple namespace with only one item.
*/
+ (MCOIMAPNamespace *) namespaceWithPrefix:(NSString *)prefix delimiter:(char)delimiter;

/** Returns the prefix of the main item of this namespace. */
- (NSString *) mainPrefix;

/** Returns the path delimiter of the main item of this namespace */
- (char) mainDelimiter;

/** Returns the list of prefixes of this namespace. */
- (NSArray * /* NSString */) prefixes;

/**
 Returns the folder path for the given list of path components in the context
 of the main item of the namespace.
*/
- (NSString *) pathForComponents:(NSArray *)components;

/**
 Returns the folder path for the given list of path components and a prefix.
 It will use the best item matching the prefix to compute the path.
*/
- (NSString *) pathForComponents:(NSArray *)components prefix:(NSString *)prefix;

/** Returns the components given a folder path. */
- (NSArray * /* NSString */) componentsFromPath:(NSString *)path;

/** Returns YES if the namespace contains the given folder path. */
- (BOOL) containsFolderPath:(NSString *)path;

@end

#endif
