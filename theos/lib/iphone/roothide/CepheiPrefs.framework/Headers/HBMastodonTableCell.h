#import "HBLinkTableCell.h"

/// The HBMastodonTableCell class in CepheiPrefs displays a button containing a person’s name, along
/// with their Mastodon username and avatar. When tapped, a Mastodon client installed on the user’s
/// device or the Mastodon website is opened to the person’s profile.
///
/// ### Specifier Parameters
/// In addition to the parameters accepted by `HBLinkTableCell`, `HBTwitterCell` accepts the
/// following:
///
/// <table class="graybox">
/// <tr>
/// <td>account</td> <td>Required. The Mastodon account of the person, in the format
/// `@user@example.com`. For example, `@gargon@mastodon.social`.</td>
/// </tr>
/// <tr>
/// <td>showAvatar</td> <td>Optional. Whether to show the avatar of the user. The default is
/// true.</td>
/// </tr>
/// <tr>
/// <td>iconURL</td> <td>Optional. The URL to an image to display. The default is no value, meaning
/// meaning to retrieve the avatar for the Mastodon username specified in the user property.</td>
/// </tr>
/// <tr>
/// <td>iconCircular</td> <td>Optional. Whether the icon should be displayed as a circle. The
/// default from `HBLinkTableCell` is NO, however, `HBTwitterCell` overrides this to YES.</td>
/// </tr>
/// </table>
///
/// ### Example Usage
/// ```xml
/// <!-- Standard size: -->
/// <dict>
/// 	<key>cellClass</key>
/// 	<string>HBMastodonTableCell</string>
/// 	<key>label</key>
/// 	<string>Chariz</string>
/// 	<key>account</key>
/// 	<string>@chariz@chariz.com</string>
/// </dict>
///
/// <!-- Big size: -->
/// <dict>
/// 	<key>big</key>
/// 	<true/>
/// 	<key>cellClass</key>
/// 	<string>HBMastodonTableCell</string>
/// 	<key>height</key>
/// 	<integer>56</integer>
/// 	<key>label</key>
/// 	<string>Chariz</string>
/// 	<key>account</key>
/// 	<string>@chariz@chariz.com</string>
/// </dict>
///
/// <!-- Without an avatar: -->
/// <dict>
/// 	<key>cellClass</key>
/// 	<string>HBMastodonTableCell</string>
/// 	<key>label</key>
/// 	<string>Chariz</string>
/// 	<key>showAvatar</key>
/// 	<false/>
/// 	<key>account</key>
/// 	<string>@chariz@chariz.com</string>
/// </dict>
/// ```

NS_SWIFT_NAME(MastodonTableCell)
@interface HBMastodonTableCell : HBLinkTableCell

@end
