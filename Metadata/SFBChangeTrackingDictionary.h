/*
 * Copyright (c) 2020 Stephen F. Booth <me@sbooth.org>
 * See https://github.com/sbooth/SFBAudioEngine/blob/master/LICENSE.txt for license information
 */

#pragma once

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*! @brief A dictionary-like object tracking changes from initial values */
@interface SFBChangeTrackingDictionary<__covariant KeyType, __covariant ObjectType> : NSObject
- (instancetype)initWithInitialValues:(NSDictionary<KeyType, ObjectType> *)initialValues;

- (nullable ObjectType)objectForKey:(KeyType)key;
- (nullable ObjectType)objectForKeyedSubscript:(KeyType)key;

- (void)setObject:(nullable ObjectType)object forKey:(KeyType<NSCopying>)key;
- (void)setObject:(nullable ObjectType)object forKeyedSubscript:(KeyType<NSCopying>)key;

- (void)removeObjectForKey:(KeyType)key;
- (void)removeAllObjects;

- (NSUInteger)count;

- (NSDictionary<KeyType, ObjectType> *) initialValues;
- (NSDictionary<KeyType, ObjectType> *) addedValues;
- (NSDictionary<KeyType, ObjectType> *) removedValues;
- (NSDictionary<KeyType, ObjectType> *) updatedValues;

- (NSDictionary<KeyType, ObjectType> *) mergedValues;

- (BOOL)hasChanges;
- (BOOL)hasChangesForKey:(KeyType)key;

- (void)mergeChanges;
- (void)revertChanges;

- (void)addEntriesFromDictionary:(NSDictionary<KeyType, ObjectType> *)dictionary;

- (void)reset;
@end

NS_ASSUME_NONNULL_END
