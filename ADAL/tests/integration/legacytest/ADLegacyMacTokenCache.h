// Copyright (c) Microsoft Corporation.
// All rights reserved.
//
// This code is licensed under the MIT License.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.


#import <Foundation/Foundation.h>
#import "ADALTokenCache.h"

#define CURRENT_WRAPPER_CACHE_VERSION 1.0

@class ADALAuthenticationError;
@class ADALTokenCacheItem;

@interface ADLegacyMacTokenCache : ADALTokenCache <ADALTokenCacheDataSource>
{
    NSMutableDictionary* _cache;
    pthread_rwlock_t _lock;
}

/*! Returns the default cache object using the ADALTokenCacheDelegate set in
    ADALAuthenticationSettings */
+ (nonnull ADLegacyMacTokenCache *)defaultCache;

- (void)setDelegate:(nullable id<ADALTokenCacheDelegate>)delegate;

- (nullable NSData *)serialize;
- (BOOL)deserialize:(nullable NSData*)data
              error:(ADALAuthenticationError * __nullable __autoreleasing * __nullable)error;

- (nullable NSArray<ADALTokenCacheItem *> *)allItems:(ADALAuthenticationError * __nullable __autoreleasing * __nullable)error;
- (BOOL)removeItem:(nonnull ADALTokenCacheItem *)item
             error:(ADALAuthenticationError * __nullable __autoreleasing * __nullable)error;

- (BOOL)validateCache:(nullable NSDictionary *)dict
                error:(ADALAuthenticationError * __nullable  __autoreleasing * __nullable)error;

- (nullable id<ADALTokenCacheDelegate>)delegate;

@end
