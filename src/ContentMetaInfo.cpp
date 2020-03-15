#include <nn/hac/ContentMetaInfo.h>

nn::hac::ContentMetaInfo::ContentMetaInfo()
{
	clear();
}

nn::hac::ContentMetaInfo::ContentMetaInfo(const ContentMetaInfo& other)
{
	*this = other;
}

void nn::hac::ContentMetaInfo::operator=(const ContentMetaInfo& other)
{
	clear();
	mRawBinary = other.mRawBinary;
	mTitleId = other.mTitleId;
	mTitleVersion = other.mTitleVersion;
	mType = other.mType;
	mAttribute = other.mAttribute;
}

bool nn::hac::ContentMetaInfo::operator==(const ContentMetaInfo& other) const
{
	return (mTitleId == other.mTitleId) \
		&& (mTitleVersion == other.mTitleVersion) \
		&& (mType == other.mType) \
		&& (mAttribute == other.mAttribute);
}

bool nn::hac::ContentMetaInfo::operator!=(const ContentMetaInfo& other) const
{
	return !(*this == other);
}

void nn::hac::ContentMetaInfo::toBytes()
{
	mRawBinary.alloc(sizeof(sContentMetaInfo));
	sContentMetaInfo* info = (sContentMetaInfo*)mRawBinary.data();

	info->id = mTitleId;
	info->version = mTitleVersion;
	info->type = (byte_t)mType;
	info->attributes = mAttribute.to_ullong();
}

void nn::hac::ContentMetaInfo::fromBytes(const byte_t* bytes, size_t len)
{
	if (len < sizeof(sContentMetaInfo))
	{
		throw fnd::Exception(kModuleName, "ContentMetaInfo too small");
	}

	const sContentMetaInfo* info = (const sContentMetaInfo*)bytes;

	mTitleId = info->id.get();
	mTitleVersion = info->version.get();
	mType = (cnmt::ContentMetaType)info->type;
	mAttribute = info->attributes;
}

const fnd::Vec<byte_t>& nn::hac::ContentMetaInfo::getBytes() const
{
	return mRawBinary;
}

void nn::hac::ContentMetaInfo::clear()
{
	mRawBinary.clear();
	mTitleId = 0;
	mTitleVersion = 0;
	mType = cnmt::ContentMetaType::Application;
	mAttribute = 0;
}

uint64_t nn::hac::ContentMetaInfo::getTitleId() const
{
	return mTitleId;
}

void nn::hac::ContentMetaInfo::setTitleId(uint64_t title_id)
{
	mTitleId = title_id;
}

uint32_t nn::hac::ContentMetaInfo::getTitleVersion() const
{
	return mTitleVersion;
}

void nn::hac::ContentMetaInfo::setTitleVersion(uint32_t ver)
{
	mTitleVersion = ver;
}	

nn::hac::cnmt::ContentMetaType nn::hac::ContentMetaInfo::getContentMetaType() const
{
	return mType;
}

void nn::hac::ContentMetaInfo::setContentMetaType(cnmt::ContentMetaType type)
{
	mType = type;
}	

const nn::hac::cnmt::ContentMetaAttribute& nn::hac::ContentMetaInfo::getAttribute() const
{
	return mAttribute;
}

void nn::hac::ContentMetaInfo::setAttribute(const nn::hac::cnmt::ContentMetaAttribute& attr)
{
	mAttribute = attr;
}
